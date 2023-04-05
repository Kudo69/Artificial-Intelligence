
import java.util.Scanner;
public class Main {
public static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        QuanLy ql=new QuanLy();
        int LuaChon;        
        do{
            showmenu();
            System.out.println("Chon : ");
            LuaChon = Integer.parseInt(sc.nextLine());
           switch(LuaChon)
           {
               case 0:System.out.println("Da thoat!");
                   break;
               case 1:ql.ChuDichVu();
                   break;
               case 2: ql.KhachThue();
                   break;                  
               default :
                   System.err.println("Nhap loi! Moi nhap lai : ");
                   break;
           }
        }while(LuaChon!=0);

    }
    public static void showmenu(){
        System.out.println("     ||=========== MENU ==========||");
        System.out.println("     || 0.Thoat.                  ||");
        System.out.println("     || 1.Chu Dich Vu             ||");
        System.out.println("     || 2.Khach Thue              ||");
        System.out.println("     ||===========================||"); 
    }    
}
