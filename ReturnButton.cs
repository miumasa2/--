using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ReturnButton : MonoBehaviour
{
    public string reScene;  // インスペクタでシーン名を指定
    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    // クリックしたときの処理
    public void OnClickReturn()
    {
        // 指定したシーンに移行
        SceneManager.LoadScene(reScene);
        FindObjectOfType<SoundManager>().PlaySeByName("魔王魂 効果音 システム49");
    }
}
