#include <iostream>
#define max 20
using namespace std;

class graph {
    int g[max][max], n, c[max], ch[max], min_dist, client_dist;
    char v[max], str[max][max], min_path[max], client_path[max];

public:
    graph(int m) {
        n = m;
        client_dist = 0;
        min_dist = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = 0;
    }
    void accept_v();
    void accept_e();
    void display();
    void dj_init(int);
    void dj_init();
    void dj(char, char, int);
};

void graph::accept_v() {
    int i = 0;
    cout << endl;
    cout << "Name of Cities: ";
    while (i < n) {
        cout << "\nEnter Name of City [" << i + 1 << "] : ";
        cin >> v[i];
        i++;
    }
}

void graph::accept_e() {
    int cst;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (i == j) {
                g[i][j] = 0;
                continue;
            }
            cout << "Distance between cities [" << v[i] << "][" << v[j] << "] :  ";
            cin >> cst;
            g[i][j] = g[j][i] = cst;
        }
}

void graph::display() {
    int i, j;
    i = 0;
    cout << "\n";
    while (i < n) {
        cout << "\t" << v[i];
        i++;
    }
    for (i = 0; i < n; i++) {
        cout << "\n" << v[i];
        for (j = 0; j < n; j++) {
            cout << "\t" << g[i][j];
        }
    }
}

void graph::dj_init() {
    for (int i = 0; i < n; i++) {
        c[i] = 9999;
        ch[i] = 0;
        for (int j = 0; j < n; j++) {
            str[i][j] = '-';
        }
    }
}

void graph::dj_init(int i) {
    for (int j = 0; j < n; j++) {
        str[i][j] = '-';
    }
}

void graph::dj(char s, char d, int f) {
    dj_init();
    int i = 0, j, l, k, flag, min = 999, cst = 0;

    while (v[i] != s)
        i++;
    c[i] = 0;
    k = 0;
    str[i][k] = v[i];
    do {
        ch[i] = 1;
        min = 999;
        for (j = 0; j < n; j++) {
            flag = 0;
            cst = c[i] + g[i][j];
            if (g[i][j] != 0 && i != j && cst < c[j]) {
                k = 0;
                c[j] = cst;
                dj_init(j);
                while (flag == 0) {
                    str[j][k] = str[i][k];
                    k++;
                    if (str[i][k] == '-')
                        flag = 1;
                }
                str[j][k] = v[j];
            }
        }
        for (l = 0; l < n; l++) {
            if (c[l] <= min && ch[l] == 0) {
                min = c[l];
                i = l;
            }
        }
    } while (v[i] != d);

    j = 0;
    if (f == 0)
        min_dist = c[i];
    else
        client_dist = c[i];
    if (f == 0)
        cout << "\nMinimum Distance : " << c[i] << "\nShortest Path : ";
    while (str[i][j] != '-') {
        if (f == 0)
            min_path[j] = str[i][j];
        if (f == 0)
            cout << " " << str[i][j];
        j++;
    }
    min_path[j] = '\0';
    cout << "\n\n";
}

int main() {
    int n, ch;
    char v1, v2;
    cout << "\nEnter Number of Cities: ";
    cin >> n;
    graph g(n);
    do {
        cout << "\nMain Menu \n1.Accept City Name\n2.Accept Routes\n3.Display\n4.Shortest Distance\n5.Exit\n\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            g.accept_v();
            break;
        case 2:
            g.accept_e();
            break;
        case 3:
            g.display();
            cout << endl;
            break;
        case 4:
            cout << "\nEnter Start Point : ";
            cin >> v1;
            cout << "Enter Destination : ";
            cin >> v2;
            g.dj(v1, v2, 0);
            cout << endl;
            break;
        }
    } while (ch != 5);
    return 0;
}
