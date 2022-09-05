using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book006jump : MonoBehaviour
{
    public void Endoption()
    {
        //メソッドの呼び出し
        StartCoroutine("kanabunn");
    }

    IEnumerator kanabunn()
    {
        //飛ぶ時の遅延
        yield return new WaitForSeconds(0.0f);
        //オブジェクトの破壊
        Destroy(gameObject);
        //飛ぶシーン名
        SceneManager.LoadScene("kanabunn");
        FindObjectOfType<SoundManager>().PlaySeByName("魔王魂 効果音 システム49");
    }
}