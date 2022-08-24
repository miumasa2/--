using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Itembuy : MonoBehaviour
{
    int ringo;
    int cookie;
    int meet;
    int power1;
    int power2;
    int power3;

    public void IB()
    {
        //メソッドの呼び出し
        StartCoroutine("ib");
    }

    IEnumerator ib()
    {
        Text t = GameObject.Find("Canvas").transform.Find("Text2").GetComponent<Text>();
        //飛ぶ時の遅延
        yield return new WaitForSeconds(0.0f);
        //テキスト型の変数を設定
        if (SceneManager.GetActiveScene().name.Equals("Buyinfo1"))
        { // Buyinfo1シーンでやりたい処理

            if (Test.money < 500)
            {
                t.text = "お金がたりません！！";
                FindObjectOfType<SoundManager>().PlaySeByName("クイズ不正解1");
            }
            else
            {
                ringo = SaveManager.ItemLoad(0) + 1;
                SaveManager.ItemSave(0, ringo);
                Test.money = Test.money - 500;
                SaveManager.MoneySave(Test.money);
                FindObjectOfType<SoundManager>().PlaySeByName("レジスターで精算");
            }
        }
        else if (SceneManager.GetActiveScene().name.Equals("Buyinfo2"))
        { // Buyinfo2シーンでやりたい処理
            if (Test.money < 1000)
            {
                t.text = "お金がたりません！！";
                FindObjectOfType<SoundManager>().PlaySeByName("クイズ不正解1");
            }
            else
            {
                cookie = SaveManager.ItemLoad(1) + 1;
                SaveManager.ItemSave(1, cookie);
                Test.money = Test.money - 1000;
                SaveManager.MoneySave(Test.money);
                FindObjectOfType<SoundManager>().PlaySeByName("レジスターで精算");
            }
        }
        else if (SceneManager.GetActiveScene().name.Equals("Buyinfo3"))
        { // Buyinfo3シーンでやりたい処理
            if (Test.money < 1500)
            {
                t.text = "お金がたりません！！";
                FindObjectOfType<SoundManager>().PlaySeByName("クイズ不正解1");
            }
            else
            {
                meet = SaveManager.ItemLoad(2) + 1;
                SaveManager.ItemSave(2, meet);
                Test.money = Test.money - 1500;
                SaveManager.MoneySave(Test.money);
                FindObjectOfType<SoundManager>().PlaySeByName("レジスターで精算");
            }
        }
        else if (SceneManager.GetActiveScene().name.Equals("Buyinfo4"))
        { // Buyinfo4シーンでやりたい処理
            if (Test.money < 500)
            {
                t.text = "お金がたりません！！";
                FindObjectOfType<SoundManager>().PlaySeByName("クイズ不正解1");
            }
            else
            {
                power1 = SaveManager.ItemLoad(3) + 1;
                SaveManager.ItemSave(3, power1);
                Test.money = Test.money - 500;
                SaveManager.MoneySave(Test.money);
                FindObjectOfType<SoundManager>().PlaySeByName("レジスターで精算");
            }
        }
        else if (SceneManager.GetActiveScene().name.Equals("Buyinfo5"))
        { // Buyinfo5シーンでやりたい処理
            if (Test.money < 1000)
            {
                t.text = "お金がたりません！！";
                FindObjectOfType<SoundManager>().PlaySeByName("クイズ不正解1");
            }
            else
            {
                power2 = SaveManager.ItemLoad(4) + 1;
                SaveManager.ItemSave(4, power2);
                Test.money = Test.money - 1000;
                SaveManager.MoneySave(Test.money);
                FindObjectOfType<SoundManager>().PlaySeByName("レジスターで精算");
            }
        }
        else if (SceneManager.GetActiveScene().name.Equals("Buyinfo6"))
        { // Buyinfo6シーンでやりたい処理
            if (Test.money < 1500)
            {
                t.text = "お金がたりません！！";
                FindObjectOfType<SoundManager>().PlaySeByName("クイズ不正解1");
            }
            else
            {
                power3 = SaveManager.ItemLoad(5) + 1;
                SaveManager.ItemSave(5, power3);
                Test.money = Test.money - 1500;
                SaveManager.MoneySave(Test.money);
                FindObjectOfType<SoundManager>().PlaySeByName("レジスターで精算");
            }
        }
    }
}
