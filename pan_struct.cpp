#include <stdio.h>
#include<stdlib.h>
// #include<Windows.h>
#include<iostream>
using namespace std;
typedef struct pcb_node {
    string name;
    int priority;
    pcb_node *next;
} *pcb;

ostream &operator<<( ostream& out, const pcb &to_print ) {
    out.width(15);
    out.setf(ios::left);
    return out << to_print->name  << "\t" << to_print->priority  << endl;
}

void helper( pcb ptr ) {

    if( !ptr->next ) {
        cout << "\t" << "*******" << endl;
        return;
    } else {
        while( ( ptr = ptr->next ) ) {
            cout << "\t" << ptr;
        }
    }
}
void display( pcb ready, pcb run, pcb block ) {
    cout << "ready:" << endl;
    helper( ready );
    cout << "run:" << endl;
    helper( run );
    cout << "block:" << endl;
    helper( block );
    setbuf(stdin, NULL);
    getchar();
    system("cls");
}

void make_ready( pcb &ready ) {      
    pcb new_node = new pcb_node;

    cout << "name: ";
    cin >> new_node->name;   
    cout << "priority: ";
    cin >> new_node->priority;
    
    new_node->next = ready->next;
    ready->next = new_node;
}
       
void delete_add( pcb &to_del, pcb &to_add ) {

    pcb work_pre = to_del,  work = work_pre->next;
    pcb aim_pre  = work_pre, aim = work;

    if( !to_del->next ) {
        cout << "操作失败" << endl;
        return;
    }
    while( work ) {
        if( work->priority < aim->priority ) {
            aim     = work;
            aim_pre = work_pre;
        }
        work_pre = work;
        work     = work->next;
    }
    aim_pre->next = aim->next;   //delete form to_del
    aim->next     = to_add->next;   //add to to_add
    to_add->next  = aim;     
}
void wake( pcb &to_del, pcb &to_add ) {
    string name;
    cout << "请输入要唤醒的进程:" << endl;
    cin >> name;
    pcb work_pre = to_del, work  = work_pre->next;
    pcb aim_pre  = work_pre, aim = work;
    while( work != NULL ) {
        if( work->name == name ) {
            aim     = work;
            aim_pre = work_pre;
            break;
        }
        work_pre = work;
        work     = work->next; 
    }
    if( work != NULL ) {
        aim_pre->next = aim->next; // delete from to_del
        aim->next = to_add->next;
        to_add->next = aim;
    } else {
        cout << "执行失败" << endl;
    }
}
void menu( pcb &ready, pcb &run, pcb &block ) {
    int choice;
    choice = 1;
    while( choice >= 1 && choice <= 6 ) {
        display( ready, run, block );
        cout << "\n1. create\n2. undo\n3. block\n4. wake\n5. dispath\n6. exit\n请输入1-6的数字\n";
        cin >> choice;
        switch( choice ) {
            case 1:
                make_ready( ready ); break;
            case 2:
                run->next = NULL; break;
            case 3:
                delete_add( run, block ); break;
            case 4:
                wake( block, ready ); break;
            case 5:
                delete_add( ready, run ); break;
            case 6: return;
        }
    }
}
void quick_add( pcb &to_add, string name_arr[], int prio_arr[] ) {
    for( int i = 0; i < 4; i++ ) {
        pcb new_node       = new pcb_node;
        new_node->name     = name_arr[i];   
        new_node->priority = prio_arr[i];
        new_node->next     = to_add->next;
        to_add->next       = new_node;
    }
}
int main(void) {
    pcb ready, run, block;

    ready       = new pcb_node;
    run         = new pcb_node;
    block       = new pcb_node;
    ready->next = run->next = block->next = NULL;

    string name_arr1[] = {"cf", "galgame", "CS-GO", "notion"};
    string name_arr2[] = {"Zen", "Chrome", "bilibili", "Alipay"};
    int prio_arr1[] = { 3, 0, 6, 7 };
    int prio_arr2[] = { 8, 2, 3, 9 };
    quick_add( ready, name_arr1, prio_arr1 );
    quick_add( block, name_arr2, prio_arr2 );
    menu( ready, run, block );
}