using System.Linq;

public class TwoToOne 
{
  static string final;
  public static string Longest (string s1, string s2) 
  {
     final = "";
     if (s1.ToLower().Contains("a")){final += "a";}
     else if (s2.ToLower().Contains("a")){final += "a";}
     if (s1.ToLower().Contains("b")){final += "b";}
     else if (s2.ToLower().Contains("b")){final += "b";}
     if (s1.ToLower().Contains("c")){final += "c";}
     else if (s2.ToLower().Contains("c")){final += "c";}
     if (s1.ToLower().Contains("d")){final += "d";}
     else if (s2.ToLower().Contains("d")){final += "d";}
     if (s1.ToLower().Contains("e")){final += "e";}
     else if (s2.ToLower().Contains("e")){final += "e";}
     if (s1.ToLower().Contains("f")){final += "f";}
     else if (s2.ToLower().Contains("f")){final += "f";}
     if (s1.ToLower().Contains("g")){final += "g";}
     else if (s2.ToLower().Contains("g")){final += "g";}
     if (s1.ToLower().Contains("h")){final += "h";}
     else if (s2.ToLower().Contains("h")){final += "h";}
     if (s1.ToLower().Contains("i")){final += "i";}
     else if (s2.ToLower().Contains("i")){final += "i";}
     if (s1.ToLower().Contains("j")){final += "j";}
     else if (s2.ToLower().Contains("j")){final += "j";}
     if (s1.ToLower().Contains("k")){final += "k";}
     else if (s2.ToLower().Contains("k")){final += "k";}
     if (s1.ToLower().Contains("l")){final += "l";}
     else if (s2.ToLower().Contains("l")){final += "l";}
     if (s1.ToLower().Contains("m")){final += "m";}
     else if (s2.ToLower().Contains("m")){final += "m";}
     if (s1.ToLower().Contains("n")){final += "n";}
     else if (s2.ToLower().Contains("n")){final += "n";}
     if (s1.ToLower().Contains("o")){final += "o";}
     else if (s2.ToLower().Contains("o")){final += "o";}
     if (s1.ToLower().Contains("p")){final += "p";}
     else if (s2.ToLower().Contains("p")){final += "p";}
     if (s1.ToLower().Contains("q")){final += "q";}
     else if (s2.ToLower().Contains("q")){final += "q";}
     if (s1.ToLower().Contains("r")){final += "r";}
     else if (s2.ToLower().Contains("r")){final += "r";}
     if (s1.ToLower().Contains("s")){final += "s";}
     else if (s2.ToLower().Contains("s")){final += "s";}
     if (s1.ToLower().Contains("t")){final += "t";}
     else if (s2.ToLower().Contains("t")){final += "t";}
     if (s1.ToLower().Contains("u")){final += "u";}
     else if (s2.ToLower().Contains("u")){final += "u";}
     if (s1.ToLower().Contains("v")){final += "v";}
     else if (s2.ToLower().Contains("v")){final += "v";}
     if (s1.ToLower().Contains("w")){final += "w";}
     else if (s2.ToLower().Contains("w")){final += "w";}
     if (s1.ToLower().Contains("x")){final += "x";}
     else if (s2.ToLower().Contains("x")){final += "x";}
     if (s1.ToLower().Contains("y")){final += "y";}
     else if (s2.ToLower().Contains("y")){final += "y";}
     if (s1.ToLower().Contains("z")){final += "z";}
     else if (s2.ToLower().Contains("z")){final += "z";}
     return final;
  }
}
