public class ExampleW{
    public static void main(){
        Scanner input = new Scanner(System.in);
        System.out.println("Give mark: ");
        int mark = input.nextInt();
        String Grade;
        switch (mark){
        case 100:
        case 99:
        case 98:
        case 97:
        case 96:
        case 95:
        case 94:
        case 93:
        case 92:
        case 91:
        case 90:{
            Grade = "A+";
            break;
        }case 89:
        case 88:
        case 87:
        case 86:
        case 85:
        case 84:
        case 83:
        case 82:
        case 81:
        case 80: {
            Grade = "A";
            break;
        }case 75:
        case 76:
        case 77:
        case 78:
        case 79:{
            Grade = "A-";
            break;
        }case 70:
        case 71:
        case 72:
        case 73:
        case 74:{
            Grade ="B+";
            break;
        } case 69:
        case 68:
        case 67:
        case 66:
        case 65:{
            Grade ="B";
            break;
        }
        case 64:
        case 63:
        case 62:
        case 61:
        case 60:{
            Grade = "C+";
            break;
        }case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59: {
            Grade = "C";
            break;
        }case 45:
        case 46:
        case 47:
        case 48:
        case 49:{
            Grade = "D";
            break;
        }case 40:
        case 41:
        case 42:
        case 43:
        case 44:{
            Grade = "E";
            break;
        }case 0:
        case 1:
        case 2:
        case 3:
        ...
        ...
        }default: {
            Grade = "null";
            break;
        }}
}
