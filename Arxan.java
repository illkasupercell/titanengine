package tictactoe;

import java.util.Scanner;

public class TicTacToe {

    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
        Scanner input = new Scanner(System.in);
        String a1 = "1";
        String a2 = "2";
        String a3 = "3";
        String a4 = "4";
        String a5 = "5";
        String a6 = "6";
        String a7 = "7";
        String a8 = "8";
        String a9 = "9";
        int inO;
        int inX = 0;
        boolean winner = false;
        PrintBoard(a1,a2,a3,a4,a5,a6,a7,a8,a9);
        System.out.printf("How to play - wait for your turn and when it comes write the number of the field that you want to draw in (from 1 to 9)\n");
        System.out.printf("Player O's turn: ");
        inO = input.nextInt();
        while (true) {
            switch (inO) {
                case 1:
                    if (a1 == "1") {
                        a1 = "O";
                    }
                    break;
                case 2:
                    if (a2 == "2") {
                    a2 = "O";
                    }
                    break;
                case 3:
                    if (a3 == "3") {
                    a3 = "O";
                    }
                    break;
                case 4:
                    if (a4 == "4") {
                    a4 = "O";
                    }
                    break;
                case 5:
                    if (a5 == "5") {
                    a5 = "O";
                    }
                    break;
                case 6:
                    if (a6 == "6") {
                    a6 = "O";
                    }
                    break;
                case 7:
                    if (a7 == "7") {
                    a7 = "O";
                    }
                    break;
                case 8:
                    if (a8 == "8") {
                    a8 = "O";                        
                    }
                    break;
                case 9:
                    if (a9 == "9") {
                    a9 = "O";
                    }
                    break;
                default:
                    System.out.printf("An error occured. Please accept it politely and restart the game.");
                    break;
            }
            System.out.printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            if (null != Winners(a1,a2,a3,a4,a5,a6,a7,a8,a9))switch (Winners(a1,a2,a3,a4,a5,a6,a7,a8,a9)) {
                case "NONE":
                    if (a1 != "1" && a2 != "2" && a3 != "3" && a4 != "4" && a5 != "5" && a6 != "6" && a7 != "7" && a8 != "8" && a9 != "9") {
                        winner = true;
                        System.out.println("DRAW!");
                        Thread.sleep(3000);
                        break;
                    } else {
                    PrintBoard(a1,a2,a3,a4,a5,a6,a7,a8,a9);
                    System.out.printf("Player X's turn: ");
                    inX = input.nextInt();
                    break;
                    }
                case "X":
                    winner = true;
                    System.out.println("X HAS WON!!!");
                    Thread.sleep(3000);
                    break;
                case "O":
                    winner = true;
                    System.out.printf("O HAS WON!!!");
                    Thread.sleep(3000);
                    break;
                default:
                    break;
            }
            if (winner) {
                break;
            }
            switch (inX) {
                case 1:
                    if (a1 == "1") {
                    a1 = "X";
                    }
                    break;
                case 2:
                    if (a2 == "2") {
                    a2 = "X";
                    }
                    break;
                case 3:
                    if (a3 == "3") {
                    a3 = "X";
                    }
                    break;
                case 4:
                    if (a4 == "4") {
                    a4 = "X";
                    }
                    break;
                case 5:
                    if (a5 == "5") {
                    a5 = "X";
                    }
                    break;
                case 6:
                    if (a6 == "6") {
                    a6 = "X";
                    }
                    break;
                case 7:
                    if (a7 == "7") {
                    a7 = "X";
                    }
                    break;
                case 8:
                    if (a8 == "8") {
                    a8 = "X";
                    }
                    break;
                case 9:
                    if (a9 == "9") {
                    a9 = "X";
                    }
                    break;
                default:
                    System.out.printf("An error occured. Please accept it politely and restart the game.");
                    break;
            }
            System.out.printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            if (null != Winners(a1,a2,a3,a4,a5,a6,a7,a8,a9))switch (Winners(a1,a2,a3,a4,a5,a6,a7,a8,a9)) {
                case "NONE":
                    if (a1 != "1" && a2 != "2" && a3 != "3" && a4 != "4" && a5 != "5" && a6 != "6" && a7 != "7" && a8 != "8" && a9 != "9") {
                        winner = true;
                        System.out.println("DRAW!");
                        Thread.sleep(3000);
                        break;
                    } else {
                    PrintBoard(a1,a2,a3,a4,a5,a6,a7,a8,a9);
                    System.out.printf("Player O's turn: ");
                    inO = input.nextInt();
                    break;
                    }
                case "X":
                    winner = true;
                    System.out.println("X HAS WON!!!");
                    Thread.sleep(3000);
                    break;
                case "O":
                    winner = true;
                    System.out.println("O HAS WON!!!");
                    Thread.sleep(3000);
                    break;
                default:
                    break;
            }
            if (winner) {
                break;
            }
        }    
    }
    
    public static void PrintBoard(String f1, String f2, String f3, String f4, String f5, String f6, String f7, String f8, String f9) {  
        System.out.printf("   %s | %s | %s \n",f1,f2,f3);
        System.out.printf("  ----------- \n");
        System.out.printf("   %s | %s | %s \n",f4,f5,f6);
        System.out.printf("  ----------- \n");
        System.out.printf("   %s | %s | %s \n",f7,f8,f9);
        System.out.printf(" \n");
    }
    
    public static String Winners(String f1, String f2, String f3, String f4, String f5, String f6, String f7, String f8, String f9) {
        if (f1 == f2 && f2 == f3 && f3 == "O") {
            return "O";
        } else if (f4 == f5 && f5 == f6 && f6 == "O") {
            return "O";
        } else if (f7 == f8 && f8 == f9 && f9 == "O") {
            return "O";
        } else if (f1 == f4 && f4 == f7 && f7 == "O") {
            return "O";
        } else if (f2 == f5 && f5 == f8 && f8 == "O") {
            return "O";
        } else if (f3 == f6 && f6 == f9 && f9 == "O") {
            return "O";
        } else if (f1 == f5 && f5 == f9 && f9 == "O") {
            return "O";
        } else if (f3 == f5 && f5 == f7 && f7 == "O") {
            return "O";
        } else if (f1 == f2 && f2 == f3 && f3 == "X") {
            return "X";
        } else if (f4 == f5 && f5 == f6 && f6 == "X") {
            return "X";
        } else if (f7 == f8 && f8 == f9 && f9 == "X") {
            return "X";
        } else if (f1 == f4 && f4 == f7 && f7 == "X") {
            return "X";
        } else if (f2 == f5 && f5 == f8 && f8 == "X") {
            return "X";
        } else if (f3 == f6 && f6 == f9 && f9 == "X") {
            return "X";
        } else if (f1 == f5 && f5 == f9 && f9 == "X") {
            return "X";
        } else if (f3 == f5 && f5 == f7 && f7 == "X") {
            return "X";
        } else {
            return "NONE";
        }
    }
}
