using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book027jump : MonoBehaviour
{
    public void Endoption()
    {
        //���\�b�h�̌Ăяo��
        StartCoroutine("oowasi");
    }

    IEnumerator oowasi()
    {
        //��Ԏ��̒x��
        yield return new WaitForSeconds(0.0f);
        //�I�u�W�F�N�g�̔j��
        Destroy(gameObject);
        //��ԃV�[����
        SceneManager.LoadScene("oowasi");
        FindObjectOfType<SoundManager>().PlaySeByName("������ ���ʉ� �V�X�e��49");
    }
}