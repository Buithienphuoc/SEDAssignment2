#include "model/Customer.h"
#include "model/Item.h"
#include "linkedlist/LinkedList.cpp"
#include "data-access-object/ItemDAO.cpp"
#include "data-access-object/CustomerDAO.cpp"

using namespace std;

int main() {

    CustomerDAO customerDao;
    ItemDAO itemDao;

    Item item1("I123-2000", "Tron Legacy", RECORD, TWODAYLOAN, 10, 1000, COMEDY);
    Item item2("I124-2000","Avatar", RECORD, TWODAYLOAN, 10, 1000, DRAMA);
    Item item3("I125-2000","Medal of Honour", GAME, TWODAYLOAN, 10, 1000);
    Item item4("I126-2000", "MMMMM", DVD, ONEWEEKLOAN, 12, 1000, COMEDY);
    Item item5("I127-2000", "AAAAA", DVD, ONEWEEKLOAN, 0, 1000, COMEDY);
    Item item6("I128-2000", "AAAAA", DVD, ONEWEEKLOAN, 0, 1000, COMEDY);
    Item item7("I129-2000", "AAAAA", DVD, ONEWEEKLOAN, 0, 1000, COMEDY);
    Customer customer1("C001", "Phuoc", "207/25/11", "0903988391", VIP);
    Customer customer2("C002", "An", "207/25/11", "0903988391", GUEST);
    Customer customer3("C003", "Minh", "207/25/11", "0903988391", REGULAR);
    Customer customer4("C004", "Trung", "207/25/11", "0903988391", VIP);
    Customer customer5("C005", "Trung", "207/25/11", "0903988391", VIP);

    customerDao.addNewCustomer(customer5);
    customerDao.addNewCustomer(customer3);
    customerDao.addNewCustomer(customer2);
    customerDao.addNewCustomer(customer1);
    customerDao.addNewCustomer(customer4);

    itemDao.addNewItem(item7);
    itemDao.addNewItem(item1);
    itemDao.addNewItem(item4);
    itemDao.addNewItem(item5);
    itemDao.addNewItem(item6);
    itemDao.addNewItem(item3);
    itemDao.addNewItem(item2);

   /* string a = "c1";
    string b = "a1";
    if (a > b){
        cout << "ahahah";
    }
    else if (a == b){
        cout << "hihi";
    }
    else if (a < b){
        cout << "hoho";
    }*/


    itemDao.showAllItem();
    itemDao.sortById();
    itemDao.showAllItem();
    itemDao.sortByTitle();
    itemDao.showAllItem();

    customerDao.showAllCustomer();
    customerDao.sortById();
    customerDao.showAllCustomer();
    customerDao.sortByName();
    customerDao.showAllCustomer();


    /*customerDao.findCustomerByName("trung").print();
    customerDao.showAllCustomer();
    customerDao.deleteCustomerById("c3");
    customerDao.showAllCustomer();

    cout << itemDao.findItemById("ss1") << endl;*/

    /*for(int i = 1; i <= 10; i++){
        customerDao.addItemForCustomer(customer4.getId(), item5);
    }
    customerDao.findCustomerById("4").showAllRentals();*/

    /*cout << itemDao.findItemById("4") << endl;
    cout << itemDao.findItemByTitle("Avatar") << endl;*/


    /*customerDao.addNewCustomer(customer1);
    customerDao.addNewCustomer(customer2);
    customerDao.addNewCustomer(customer3);
    customerDao.addNewCustomer(customer4);

    customerDao.showAllCustomer();
    customerDao.swap(customer1,customer2);
    customerDao.swap(customer3,customer4);
    customerDao.showAllCustomer();
    customerDao.swap(customer1,customer3);
    customerDao.showAllCustomer();*/

    return 0;
}
