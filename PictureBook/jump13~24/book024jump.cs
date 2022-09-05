using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class book024jump : MonoBehaviour
{
    public void Endoption()
    {
        //メソッドの呼び出し
        StartCoroutine("sabakukinnmogura");
    }

    IEnumerator sabakukinnmogura()
    {
        //飛ぶ時の遅延
        yield return new WaitForSeconds(0.0f);
        //オブジェクトの破壊
        Destroy(gameObject);
        //飛ぶシーン名
        SceneManager.LoadScene("sabakukinnmogura");
        FindObjectOfType<SoundManager>().PlaySeByName("魔王魂 効果音 システム49");
    }
}