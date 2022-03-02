#include <bits/stdc++.h>
using namespace std;
ifstream file("Input.txt");
class Batsmen
{
public:
    string name = "";
    string ytb = "yet to bat";
    int runs = 0;
    int balls = 0;
    int fours = 0;
    int sixers = 0;
    void setName(string name)
    {
        this->name = name;
    }
    void setRuns(int runs)
    {
        this->runs = runs;
    }
    void setBalls(int balls)
    {
        this->balls = balls;
    }
    void setFours(int fours)
    {
        this->fours = fours;
    }
    void setSixers(int sixers)
    {
        this->sixers = sixers;
    }
    void setYtb(string ytb)
    {
        this->ytb = ytb;
    }

    string getYtb()
    {
        return ytb;
    }
    string getName()
    {
        return name;
    }
    int getRuns()
    {
        return runs;
    }
    int getBalls()
    {
        return balls;
    }
    int getFours()
    {
        return fours;
    }
    int getSixers()
    {
        return sixers;
    }
};

int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}

int main()
{
    freopen("output.txt", "w", stdout);
    list<string> lis;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            lis.push_back(line);
        }
        string names[] = {"Rohit Sharma", "S Dhawan", "Kohli", "Pant", "Pandey", "Krunal", "Jadeja", "Washington Sundar", "Bhuvneshwar Kumar", "Khaleel Ahmed", "Navdeep Saini "};
        list<Batsmen> btlist;

        for (int j = 0; j < 11; j++)
        {
            Batsmen b;
            b.setName(names[j]);
            btlist.push_back(b);
        }
        for (auto it = lis.begin(); it != lis.end(); it++)
        {
            regex r("[0-9]+.[0-9]");
            bool b = true;
            if (regex_match(*it, r))
            {
                it++;
                string run = *it;
                it++;
                for (auto bt = btlist.begin(); bt != btlist.end(); bt++)
                {
                    string line3 = *it;
                    if (isSubstring(bt->getName(), line3) != -1)
                    {
                        bt->setYtb("batted");
                        if (run == ".")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                        }
                        if (run == "1")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 1);
                        }
                        if (run == "2")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 2);
                        }
                        if (run == "3")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 3);
                        }
                        if (run == "4")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 4);
                            bt->setFours(bt->getFours() + 1);
                        }
                        if (run == "5")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 5);
                            bt->setFours(bt->getFours() + 1);
                        }
                        if (run == "6")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 6);
                            bt->setSixers(bt->getSixers() + 1);
                        }
                        if (run == "7")
                        {
                            bt->setBalls(bt->getBalls() + 1);
                            bt->setRuns(bt->getRuns() + 7);
                            bt->setSixers(bt->getSixers() + 1);
                        }
                        break;
                    }
                }
            }
        }

        int cnt = 1;
        cout << "Here are the score cards : " << endl;
        for (auto bt = btlist.begin(); bt != btlist.end(); bt++)
        {
            cout << "batsmen : " << cnt << endl;
            cout << "batsmen name : " << bt->getName() << endl;
            cout << "Score : " << bt->getRuns() << endl;
            cout << "batting status : " << bt->getYtb() << endl;
            cout << "balls : " << bt->getBalls() << endl;
            cout << "sixers : " << bt->getSixers() << endl;
            cout << "fours : " << bt->getFours() << endl;

            cout << endl;
            cnt++;
        }
    }
    fclose(stdout);
    return 0;
}
