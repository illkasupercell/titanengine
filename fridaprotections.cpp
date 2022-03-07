void printNumber(int Number){
    while(Number>0){
        int i=Number%10;
        switch(i) {
            case 1 : cout << '1'; // prints "1",
            case 2 : cout << '2'; // then prints "2"
            case 3 : cout << '3'; // then prints "3"
            case 4 : cout << '4'; // then prints "4"
            case 5 : cout << '5'; // then prints "5"
            case 6 : cout << '6'; // then prints "6"
            case 7 : cout << '7'; // then prints "7"
            case 8 : cout << '8'; // then prints "8"
            case 9 : cout << '9'; // then prints "9"
            case 0 : cout << '0'; // then prints "0"
            default : cout<<'5'; // :|
        }
        Number=Number/10;
    }
}
