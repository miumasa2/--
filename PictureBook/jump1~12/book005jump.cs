using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book005jump : MonoBehaviour
{
    public void Endoption()
    {
        //���\�b�h�̌Ăяo��
        StartCoroutine("miyamakuwagata");
    }

    IEnumerator miyamakuwagata()
    {
        //��Ԏ��̒x��
        yield return new WaitForSeconds(0.0f);
        //�I�u�W�F�N�g�̔j��
        Destroy(gameObject);
        //��ԃV�[����
        SceneManager.LoadScene("miyamakuwagata");
        FindObjectOfType<SoundManager>().PlaySeByName("������ ���ʉ� �V�X�e��49");
    }
}