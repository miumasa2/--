using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book022jump : MonoBehaviour
{
    public void Endoption()
    {
        //���\�b�h�̌Ăяo��
        StartCoroutine("gazeru");
    }

    IEnumerator gazeru()
    {
        //��Ԏ��̒x��
        yield return new WaitForSeconds(0.0f);
        //�I�u�W�F�N�g�̔j��
        Destroy(gameObject);
        //��ԃV�[����
        SceneManager.LoadScene("gazeru");
        FindObjectOfType<SoundManager>().PlaySeByName("������ ���ʉ� �V�X�e��49");
    }
}