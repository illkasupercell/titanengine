int __fastcall sub_23CB90(int a1)
{
  int v1; // r0
  int v2; // r4
  _BYTE v4[24]; // [sp+0h] [bp-18h] BYREF

  v1 = sub_5B5038(*(_DWORD *)(a1 + 4), dword_97ED90);
  sub_3FAF38(v4, v1);
  v2 = 0;
  if ( !sub_2153DC(v4, aCoinrush) )
  {
    v2 = 2;
    if ( !sub_2153DC(v4, aAttackdefend) )
    {
      v2 = 7;
      if ( !sub_2153DC(v4, aBossfight) )
      {
        v2 = 3;
        if ( !sub_2153DC(v4, aBountyhunter) )
        {
          v2 = 5;
          if ( !sub_2153DC(v4, aLaserball) )
          {
            v2 = 6;
            if ( !sub_2153DC(v4, aBattleroyale) )
            {
              v2 = 9;
              if ( !sub_2153DC(v4, aBattleroyalete) )
              {
                v2 = 8;
                if ( !sub_2153DC(v4, aSurvival) )
                {
                  v2 = 10;
                  if ( !sub_2153DC(v4, aRaid) )
                  {
                    v2 = 18;
                    if ( !sub_2153DC(v4, aRaid_towncrush) )
                    {
                      v2 = 11;
                      if ( !sub_2153DC(v4, aRobowars) )
                      {
                        v2 = 12;
                        if ( !sub_2153DC(v4, aTutorial_0) )
                        {
                          v2 = 13;
                          if ( !sub_2153DC(v4, aTraining) )
                          {
                            v2 = 14;
                            if ( !sub_2153DC(v4, aBossrace) )
                            {
                              v2 = 15;
                              if ( !sub_2153DC(v4, aSolobounty) )
                              {
                                v2 = 16;
                                if ( !sub_2153DC(v4, aCapturetheflag) )
                                {
                                  v2 = 17;
                                  if ( !sub_2153DC(v4, aKingofhill) )
                                  {
                                    sub_1DAADC(aWrongGameMode);
                                    v2 = -1;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  sub_460788(v4);
  return v2;
}
