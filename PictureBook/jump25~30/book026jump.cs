using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book026jump : MonoBehaviour
{
    public void Endoption()
    {
        //メソッドの呼び出し
        StartCoroutine("youmu");
    }

    IEnumerator youmu()
    {
        //飛ぶ時の遅延
        yield return new WaitForSeconds(0.0f);
        //オブジェクトの破壊
        Destroy(gameObject);
        //飛ぶシーン名
        SceneManager.LoadScene("youmu");
        FindObjectOfType<SoundManager>().PlaySeByName("魔王魂 効果音 システム49");
    }
}