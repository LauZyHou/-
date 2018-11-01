#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

char c[65535];//��ÿ�ζ�ȡ�Ķ���
FILE * fp;//�����ļ����ļ�ָ��
char key;//����
bool ok = false; //ָʾ���ļ�ʧ��

char pat[220];//Ҫ���ҵĴ�
char out[220];//Ҫ����Ĵ�

using namespace std;

bool openFile(const char* fileName) {
    fp = fopen(fileName, "r");//�������ļ�
    if(fp == nullptr) {
        puts("���ļ�ʧ��");
        return false;
    }
    return true;
}

//��ȫ��������ָ���ַ���
void findInAll() {
    cout << "*****************************************" << endl;
    //ÿ�ζ�ȡһ��
    while(fgets(c, 65535, fp) != nullptr) {
        char *pos = strstr(c, pat); //������в��ҵ�һ������������λ��
        if(pos == nullptr)
            continue;
        //����ҵ���һ��,�����ж��
        do {
            if(pos - c > 0 && pos - c < 40) { //�㹻С
                strncpy(out, c, 200);
            } else {
                strncpy(out, pos - 40, 200);
            }
            cout << out << "\n";
            cout << "*****************************************" << endl;
            pos = strstr(pos + 1, pat);//��һ��
        } while(pos != nullptr && pos > c);
    }
}

//����ڲ���
void searchInQuestion() {
    cout << "*****************************************" << endl;
    int willLine = 0; //������Ҫ���������
    //ÿ�ζ�ȡһ��
    while(fgets(c, 65535, fp) != nullptr) {
        char *pos = strstr(c, pat); //������в��ҵ�һ������������λ��
        if(pos != nullptr) { //�ҵ��µ�ƥ��
            willLine = 4;
            cout << c;
        } else if(willLine > 0) {
            willLine--;
            cout << c;
            if(willLine == 0) //��1�е�0��
                cout << "*****************************************" << endl;
        }
    }
}

int main() {
    system("color F0");//��������,�ı���ɫ
    while(true) {
        cout << "----'a':Article search----\n";
        cout << "----'s':Search in question bank----\n";
        cout << "----any key others to quit----\n";
        cin >> key;
        if(key == 'a') {//ȫ������
            getchar();//�յ�\n
            ok = openFile("input1");
            if(!ok)
                break;//���ļ�ʧ��
            while(true) {
                cout << ">>> [input pat str,'q' to quit]\n";
                gets(pat);//Ҫ���ҵĴ�
                if(pat[0] == 'q') {
                    fclose(fp);
                    break;
                }
                findInAll();//ȫ�Ĳ���
                rewind(fp);//�ļ�ָ�����
            }
        } else if(key == 's') {//����ڲ���
            getchar();//�յ�\n
            ok = openFile("input2");
            if(!ok)
                break;//���ļ�ʧ��
            while(true) {
                cout << ">>> [input pat str,'q' to quit]\n";
                gets(pat);//Ҫ���ҵĴ�
                if(pat[0] == 'q') {
                    fclose(fp);
                    break;
                }
                searchInQuestion();//����ڲ���
                rewind(fp);//�ļ�ָ�����
            }
        } else {
            break;
        }
    }
    system("pause");
    return 0;
}
