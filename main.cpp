#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void wypisz_plansze (int plansza[10][10])
{
    
    for(int i=0; i<10; i++)
    {
        
        cout.width(2);
        for (int k=0; k<10; k++)
        {
            
            cout.width(3);
            cout<< plansza[i][k]<<" ";
        }
        cout<<endl;
    }
}

void ustaw(int plansza[10][10])
{
    int kierunek, x, y;
    int w=5;
    
    for (int n=4; n>0 ; n--)
    {
    for(int p=0; p<w-n; p++)
    {

    bool czy_miejsce = true;
    bool czy_kierunek = true;
    int czy_wolne=0;
        

    while(czy_miejsce)
    {
        x=rand()%10;
        y=rand()%10;
        
        if(plansza[x][y]==0)
        {
            czy_miejsce=false;
            
            while(czy_kierunek)
            {
                kierunek= rand()%4;
                czy_wolne=0;
                
                if(kierunek==0)             // w prawo
                {
                    if(y+n-1<10)
                    {
                        for(int t=y; t<y+n+1; t++)
                        {
                            if (plansza[x][t]!=0) czy_wolne++;
                        }
                        
                        
            
                    if(czy_wolne==0)
                    {
                        czy_kierunek=false;
                        for(int i=0;i<n;i++)
                        {
                            plansza[x][y+i]=n;
                        }
                        
                        for (int i=y; i<y+n; i++)
                        {
                            if (x+1<10)plansza[x+1][i]= -1;
                            if (x-1>=0) plansza[x-1][i]= -1;
                        }
                        
                        if (y-1>=0)plansza [x][y-1]=-1;
                        if (y+n<10)plansza [x][y+n]=-1;
                        
                        if(x-1>=0 && y-1>=0)plansza [x-1][y-1]=-1;
                        if(x+1<10 && y-1>=0)plansza [x+1][y-1]=-1;
                        
                        if(x-1>=0 && y+n<10) plansza [x-1][y+n]=-1;
                        if(x+1<10 && y+n<10) plansza [x+1][y+n]=-1;
                        
                    }
                }
                }
                
                else if (kierunek==1)            // w gore
                {
                    if(x-n+1>=0)
                    {
                        for (int t=x-n; t<=x; t++)
                        {
                            if (plansza[t][y]!=0) czy_wolne++;
                        }
                        
                    
                        
                    if (czy_wolne==0)
                    {
                        czy_kierunek=false;
                        
                        for(int i=n-1;i>=0;i--)
                        {
                            plansza[x-i][y]=n;
                        }
                        
                        
                        
                        for (int i=x-n+1; i<=x; i++)
                        {
                            if (y-1>=0) plansza[i][y-1]= -1;
                            if (y+1<10) plansza[i][y+1]= -1;
                        }
                        
                        if (x+1<10) plansza [x+1][y]=-1;
                        if(x-n>=0) plansza [x-n][y]=-1;
                        
                        if (x+1<10 && y-1>=0) plansza [x+1][y-1]=-1;
                        if (x-1>=0 && y+1<10) plansza [x+1][y+1]=-1;
                        
                        if (x-n>=0 && y-1>=0) plansza [x-n][y-1]=-1;
                        if (x+n<10 && y+1<10) plansza [x-n][y+1]=-1;
                    }
                }
                }
                
                else if (kierunek==2)            // w dol
                {
                    if(x+n-1<10)
                    {
                        for (int t=x; t<x+n-1; t++)
                        {
                            if(plansza[t][y]!=0) czy_wolne++;
                        }
                        
                        
                    
                       if(czy_wolne==0)
                    {
                        czy_kierunek=false;
                        for(int i=n-1;i>=0;i--)
                        {
                            plansza[x+i][y]=n;
                        }
                        
                        for (int i=x; i<x+n ; i++)
                        {
                            if(y-1>=0) plansza[i][y-1]= -1;
                            if(y+1<10) plansza[i][y+1]= -1;
                        }
                        
                        if (x+n<10)plansza [x+n][y]=-1;
                        if (x-1>=0)plansza [x-1][y]=-1;
                        
                        if(x-1>=0 && y-1>=0) plansza[x-1][y-1]=-1;
                        if(x-1>=0 && y+1<10) plansza[x-1][y+1]=-1;
                        
                        if(x+n<10 && y-1>=0) plansza[x+n][y-1]=-1;
                        if(x+n<10 && y+1<10) plansza[x+n][y+1]=-1;
                    }
                }
                }
                
                else if (kierunek==3)            // w lewo
                {
                    if(y-n+1>=0)
                    {
                        for(int t=y-n; t<=y;t++)
                        {
                            if(plansza[x][t]!=0) czy_wolne++;
                        }
                        
                     
                        
                        
                    
                        
                    if (czy_wolne==0)
                    {
                        czy_kierunek=false;
                        for(int i=n-1;i>=0;i--)
                        {
                            plansza[x][y-i]=n;
                        }
                        
                        for (int i=y-n+1; i<=y ; i++)
                        {
                            if(x-1>=0) plansza[x-1][i]= -1;
                            if(x+1<10) plansza[x+1][i]= -1;
                        }
                        
                        if(y+1<10) plansza [x][y+1]=-1;
                        if(y-n>=0) plansza [x][y-n]=-1;
                        
                        if(x+1<10 && y+1<10) plansza[x+1][y+1]=-1;
                        if(x-1>=0 && y+1<10) plansza[x-1][y+1]=-1;
                        
                        if(x-1>=0 && y-n>=0) plansza [x-1][y-n]=-1;
                        if(x+1<10 && y-n>=0) plansza [x+1][y-n]=-1;
                        
                    }
                    }
                    
                }
                
                else czy_kierunek=true;
            }
            
        }
        
        else czy_miejsce=true;
    }
   
    }
    }
}

void zamiana(int plansza[10][10])
{
    for(int i=0; i<10; i++)
    {
        if(i==0)cout<<"      A  B  C  D  E  F  G  H  I  J  "<<endl;
        if(i==0) cout<<"__________________________________"<<endl<<endl;
        cout.width(2);
        cout<<i+1<<"| ";
        for (int j=0; j<10; j++)
        {
            if (plansza[i][j]>0)
            {
                cout.width(3);
                cout<< "x";
            }
            if (plansza[i][j]==0)
            {
                cout.width(3);
                cout<< "-";
            }
            if (plansza[i][j]<0)
            {
                cout.width(3);
                cout<< "-";
            }
        }
        cout<<endl;
    }
}

int main()
{
    srand(time(NULL));
    
    int plansza [10][10]{};
    
    ustaw (plansza);
    wypisz_plansze(plansza);
    
    cout<<endl<<endl;
    
    zamiana(plansza);
    cout<<endl<<endl;
    
}



    
