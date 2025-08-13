import java.util.Scanner;

// Class for customer detail
class Customer {
    int c_no;       // Card number
    int pass;       // Password of the user
    int balance;    // Account balance
    Customer next;  // Link to next profile
}

public class ATM {
    static Scanner sc = new Scanner(System.in);

    // Function to check if card user exists
    static Customer checkUser(Customer start, int temp_no) {
        Customer ptr = start;
        while (ptr != null) {
            if (ptr.c_no == temp_no) {
                return ptr;
            }
            ptr = ptr.next;
        }
        return null;
    }

    // Function to check password digit count
    static int checkCount(int temp_pass) {
        int count = 0;
        while (temp_pass > 0) {
            temp_pass /= 10;
            count++;
        }
        return count;
    }

    // Function to create new account for new card user
    static Customer create(int temp_no) {
        System.out.print("\nDO YOU WANT TO ACTIVATE YOUR CARD (IF YES PRESS 1 OTHERWISE 2): ");
        int n = sc.nextInt();
        if (n == 1) {
            Customer temp = new Customer();
            temp.c_no = temp_no;
            temp.balance = 10000; // default balance
            System.out.print("ENTER THE PASSWORD (4 digit): ");
            int temp_pass = sc.nextInt();
            while (checkCount(temp_pass) != 4) {
                System.out.print("ENTER THE PASSWORD CORRECTLY!!\nRE-ENTER PASSWORD EXACTLY IN 4 DIGIT: ");
                temp_pass = sc.nextInt();
            }
            temp.pass = temp_pass;
            System.out.println("PASSWORD SAVED SUCCESSFULLY");
            temp.next = null;
            return temp;
        } else {
            System.out.println("REMOVE YOUR CARD , THANK YOU !!");
            return null;
        }
    }

    // Function to insert new customer into linked list
    static Customer insert(Customer start, int temp_no) {
        Customer temp = create(temp_no);
        if (temp == null) return start;
        if (start == null) {
            start = temp;
        } else {
            Customer ptr = start;
            while (ptr.next != null) {
                ptr = ptr.next;
            }
            ptr.next = temp;
        }
        return start;
    }

    // Withdrawal function
    static void withdrawal(Customer ptr) {
        System.out.print("ENTER THE WITHDRAWAL AMOUNT: ");
        int amt = sc.nextInt();
        if (amt < ptr.balance) {
            int x = 0;
            while (x != 2) {
                System.out.print("ENTER THE PASSWORD: ");
                int pass = sc.nextInt();
                if (ptr.pass == pass) break;
                System.out.println("WRONG PASSWORD!! RETRY");
                x++;
            }
            if (x == 2) {
                System.out.println("SORRY REMOVE YOUR CARD");
                return;
            }
            ptr.balance -= amt;
            System.out.printf("COLLECT YOUR %d AMOUNT RUPEES\nTHANK YOU VISIT AGAIN\n", amt);
        } else {
            System.out.println("\nYOUR WITHDRAWABLE AMOUNT IS NOT PRESENT IN YOUR ACCOUNT");
        }
    }

    // Pin reset
    static void pinReset(Customer ptr) {
        System.out.print("ENTER YOUR PASSWORD: ");
        int pass = sc.nextInt();
        if (ptr.pass == pass) {
            System.out.print("ENTER YOUR NEW PASSWORD: ");
            ptr.pass = sc.nextInt();
            System.out.println("THANK YOU VISIT AGAIN");
        } else {
            System.out.println("SORRY REQUEST CANCELLED DUE TO WRONG PASSWORD\nCOLLECT YOUR CARD");
        }
    }

    // Balance check
    static void checkBalance(Customer ptr) {
        int x = 0;
        while (x != 2) {
            System.out.print("ENTER THE PASSWORD: ");
            int pass = sc.nextInt();
            if (ptr.pass == pass) {
                System.out.println("YOUR ACCOUNT BALANCE = " + ptr.balance);
                System.out.println("THANK YOU VISIT AGAIN");
                return;
            }
            System.out.println("WRONG PASSWORD!! RETRY");
            x++;
        }
        if (x == 2) {
            System.out.println("SORRY REMOVE YOUR CARD");
        }
    }

    // Cash deposit
    static void cashDeposit(Customer ptr) {
        System.out.print("ENTER THE AMOUNT YOU WANT TO DEPOSIT: ");
        int dep = sc.nextInt();
        int x = 0;
        while (x != 2) {
            System.out.print("ENTER THE PASSWORD: ");
            int pass = sc.nextInt();
            if (ptr.pass == pass) {
                ptr.balance += dep;
                System.out.println("THANK YOU VISIT AGAIN");
                return;
            }
            System.out.println("WRONG PASSWORD!! RETRY");
            x++;
        }
        if (x == 2) {
            System.out.println("SORRY REMOVE YOUR CARD");
        }
    }

    public static void main(String[] args) {
        Customer start = null;
        while (true) {
            System.out.print("\nWelcome To Our ATM\nINSERT YOUR CARD NO: ");
            int temp_no = sc.nextInt();
            Customer temp = checkUser(start, temp_no);
            if (temp == null) {
                start = insert(start, temp_no);
            } else {
                System.out.print(
                        "PRESS 1 FOR CASH WITHDRAWAL\n" +
                        "PRESS 2 FOR PIN RESET\n" +
                        "PRESS 3 FOR CHECK BALANCE\n" +
                        "PRESS 4 FOR CASH DEPOSIT\n" +
                        "ENTER YOUR CHOICE: ");
                int n = sc.nextInt();
                switch (n) {
                    case 1 -> withdrawal(temp);
                    case 2 -> pinReset(temp);
                    case 3 -> checkBalance(temp);
                    case 4 -> cashDeposit(temp);
                    default -> System.out.println("ENTER THE CORRECT OPTION !!!");
                }
            }
        }
    }
}
