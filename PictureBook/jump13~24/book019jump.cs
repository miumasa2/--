using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book019jump : MonoBehaviour
{
    public void Endoption()
    {
        //���\�b�h�̌Ăяo��
        StartCoroutine("rakuda");
    }

    IEnumerator rakuda()
    {
        //��Ԏ��̒x��
        yield return new WaitForSeconds(0.0f);
        //�I�u�W�F�N�g�̔j��
        Destroy(gameObject);
        //��ԃV�[����
        SceneManager.LoadScene("rakuda");
        FindObjectOfType<SoundManager>().PlaySeByName("������ ���ʉ� �V�X�e��49");
    }
}