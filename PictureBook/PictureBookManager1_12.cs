using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PictureBookManager1_12 : MonoBehaviour
{
    public Button [] button;
    public Font font;
    // Start is called before the first frame update
    void Start()
    {
        for(int i=0; i<button.Length; i++)
        {
            Text text = button[i].gameObject.transform.GetChild(0).gameObject.GetComponent<Text>();
            if(SaveManager.CardFlagLoad(i) == false)
            {
                button[i].interactable = false;
                text.text = (i+1).ToString("000") + "　―――――――";
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
