using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField] float flap = 1000f;
    [SerializeField] float scroll = 5f;
    [SerializeField] float dex; // ����
    private int rev = 1;
    private float direction = 0f, invincibleTime, x;
    Rigidbody2D rb2d;
    public bool jump { get; set; }          // �W�����v
    public bool carry { get; set; }         // �^��
    public bool go { get; set; }            // �ꎞ��~���̔��]�h�~
    private bool have = false;              // ����
    private bool dash = false;              // �_�b�V��
    private bool invincible = false;
    private HP hp;                          // HP�N���X
    private int speed = 1;                  // �X�s�[�h
    private bool stopper = false;           // �X�g�b�p�[
    [SerializeField] Animator animator;     // Animator���擾
    [SerializeField] Sprite ps;
    private SpriteRenderer psr;
    private AudioSource audioSource;
    [SerializeField] AudioClip Jump;
    //�ǉ�
    [SerializeField] AudioClip Humu;

    private void Start()
    {
        rb2d = GetComponent<Rigidbody2D>();
        GameObject HP = GameObject.Find("H");                               // HP���I�u�W�F�N�g�̖��O����擾���ĕϐ��Ɋi�[
        hp = HP.GetComponent<HP>();                                         // HP�̒��ɂ���HP���擾���ĕϐ��Ɋi�[
        psr = gameObject.GetComponent<SpriteRenderer>();
        audioSource = GetComponent<AudioSource>();
    }

    private void Update()
    {
        Vector3 scale = transform.localScale;       // �X�P�[���l���o��

        if (Input.GetKey("left shift") || Input.GetKey("joystick button 0"))         // �_�b�V�����̃X�s�[�h�l
        {
            if (!have && jump && Mathf.Abs(x) == 1 && !invincible)
            {
                speed = 3;
                animator.SetBool("dash", true);
                dash = true;
            }
        }

        if (!Input.GetKey("left shift") && !Input.GetKey("joystick button 0"))           // �������̃X�s�[�h�l
        {
            if (!stopper && !invincible)
            {
                speed = 1;
                animator.SetBool("dash", false);
                dash = false;
            }
        }

        x = Input.GetAxisRaw("Horizontal");

        if (Mathf.Abs(x) == 1 && !invincible)
        {
            animator.SetBool("walk", true);
            scale.x = x;
            direction = x * speed;
        }
        else
        {
            animator.SetBool("walk", false);
            direction = x * speed;
            speed = 1;
        }

        /*if (Input.GetKey(KeyCode.RightArrow))
        {
            animator.SetBool("walk", true);
            scale.x = 1;        // �E������
            direction = 1f * speed;
        }
        else if (Input.GetKey(KeyCode.LeftArrow))
        {
            animator.SetBool("walk", true);
            scale.x = -1;       // ��������
            direction = -1f * speed;
        }
        else
        {
            direction = 0f;     // �Î~
            animator.SetBool("walk", false);
        }*/

        // ���������
        if (!go == true)
            transform.localScale = scale;

        //�L������y����direction������scroll�̗͂�������
        rb2d.velocity = new Vector2(scroll * direction, rb2d.velocity.y);

        // �W�����v����
        if (Input.GetKeyDown("space") || Input.GetKeyDown("joystick button 1"))
        {
            if (jump && !invincible)
            {
                audioSource.PlayOneShot(Jump);
                if (dash)
                {
                    rb2d.AddForce(Vector2.up * (flap / 0.8f));
                }
                else
                {
                    rb2d.AddForce(Vector2.up * (flap * 1.1f));
                    animator.SetBool("jump", true);
                }
            }
        }



        if (invincible)
        {
            invincibleTime -= Time.deltaTime;
            if (invincibleTime >= 0.0f)
            {
                // rb2d.AddForce(Vector2.right * 100f * -this.gameObject.transform.localScale.x, ForceMode2D.Force);
                speedManager(0);
                transform.position -= new Vector3(0.01f * transform.localScale.x, 0, 0);
            }
            else
            {
                speedManager(1);
                invincibleTime = 1.5f;
                invincible = false;
                animator.SetBool("damage", false);

            }
        }
    }

    void OnCollisionEnter2D(Collision2D other)
    {
        if (other.gameObject.CompareTag("Enemy") && jump && !invincible)
        {
            invincibleTime = 0.5f;
            animator.SetBool("damage", true);
            invincible = true;
            hp.Damage();    // �_���[�W����
        }
        else if (other.gameObject.CompareTag("Enemy") && !jump)
        {
            rb2d.AddForce(Vector2.up * (flap * 1.2f));
            animator.SetBool("jump", true);
            //�ǉ�
            audioSource.PlayOneShot(Humu);
        }



    }

    public void startPlayer()
    {
        psr.sprite = ps;
    }

    public bool getHave
    {
        get { return this.have; }
    }

    public void setHave(bool have)
    {
        this.have = have;
    }

    public bool getDash
    {
        get { return this.dash; }
    }

    public void speedManager(int speed)
    {
        this.speed = speed;
        if (speed == 0)
            stopper = true;
        else
            stopper = false;
    }

    void OnCollisionStay2D(Collision2D other)
    {

        // �����ɏՓ˂����ꍇ�̔��]����
        if (other.gameObject.CompareTag("Goal"))
        {
            // dex�̑����������ړ�
            transform.position += new Vector3(dex * Time.deltaTime * rev, 0, 0);
        }
    }
}
