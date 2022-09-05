using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book025jump : MonoBehaviour
{
    public void Endoption()
    {
        //メソッドの呼び出し
        StartCoroutine("hato");
    }

    IEnumerator hato()
    {
        //飛ぶ時の遅延
        yield return new WaitForSeconds(0.0f);
        //オブジェクトの破壊
        Destroy(gameObject);
        //飛ぶシーン名
        SceneManager.LoadScene("hato");
        FindObjectOfType<SoundManager>().PlaySeByName("魔王魂 効果音 システム49");
    }
}