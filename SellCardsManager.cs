using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class SellCardsManager : MonoBehaviour
{
    public static int[] sellCardsNum = Array.Empty<int>();
    public static int[] selectNum = Array.Empty<int>();

    public SellCardPlaceManager sellCardPlace;

    public int price;

    void Awake()
    {
        if (sellCardsNum.Length < CardData.GetAllCardDataNum())
        {
            int n = sellCardsNum.Length;
            Array.Resize(ref sellCardsNum, CardData.GetAllCardDataNum());
            for (int i = n; i < sellCardsNum.Length; i++)
            {
                sellCardsNum[i] = 0;
            }
        }

        SetSellCardsPrice();
    }

    public void SetSellCard(int id)
    {
        if (SaveManager.CardNumLoad(id) <= sellCardsNum[id])
        {
            return;
        }

        sellCardsNum[id] += 1;

        for (int i = 0; i < selectNum.Length; i++)
        {
            if (selectNum[i] == id)
            {
                switch (new CardData(id).rarity)
                {
                    case 0:
                        price += 10;
                        break;
                    case 1:
                        price += 30;
                        break;
                    case 2:
                        price += 50;
                        break;
                    default:
                        return;
                }
            }
        }
        Array.Resize(ref selectNum, selectNum.Length + 1);
        selectNum[selectNum.Length - 1] = id;

        SetSellCardsPrice();

        sellCardPlace.SetSellCards();
    }

    public void ResetNum()
    {
        for (int i = 0; i < sellCardsNum.Length; i++)
        {
            sellCardsNum[i] = 0;
        }
        selectNum = Array.Empty<int>();
        price = 0;
    }

    public void SetSellCardsPrice()
    {
        price = 0;
        for (int i = 0; i < selectNum.Length; i++)
        {
            int id = selectNum[i];
            switch (new CardData(id).rarity)
            {
                case 0:
                    price += 10;
                    break;
                case 1:
                    price += 30;
                    break;
                case 2:
                    price += 50;
                    break;
            }
        }
    }
}
