using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ReturnButton : MonoBehaviour
{
    public string reScene;  // �C���X�y�N�^�ŃV�[�������w��
    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    // �N���b�N�����Ƃ��̏���
    public void OnClickReturn()
    {
        // �w�肵���V�[���Ɉڍs
        SceneManager.LoadScene(reScene);
        FindObjectOfType<SoundManager>().PlaySeByName("������ ���ʉ� �V�X�e��49");
    }
}
