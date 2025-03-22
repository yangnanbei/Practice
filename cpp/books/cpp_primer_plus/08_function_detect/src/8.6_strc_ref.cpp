#include <iostream>
#include <string>

struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
    free_throws one = {"Ifels", 13, 14, 0.0};
    free_throws two = {"Javens", 10, 16, 0.0};
    free_throws three = {"Kobayshi", 6, 14, 0.0};
    free_throws four = {"Lebron", 18, 16, 0.0};
    free_throws five = {"Shaq", 17, 16, 0.0};
    free_throws team = {"Thunder", 0, 0, 0.0};

    std::cout << "Name          Made  Attempts  Percent\n";
    std::cout << "-----------------------------------\n";

    set_pc(one);
    display(one);
    set_pc(two);
    display(two);
    set_pc(three);
    display(three);
    set_pc(four);
    display(four);
    set_pc(five);
    display(five);

    accumulate(team, one);
    accumulate(team, two);
    accumulate(team, three);
    accumulate(team, four);
    accumulate(team, five);

    std::cout << "\nTeam totals:\n";
    std::cout << "-----------------------------------\n";
    set_pc(team);
    display(team);

    return 0;
}

void display(const free_throws & ft)
{
    using std::cout;
    using std::endl;
    cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    cout << ft.name << "      " << ft.made << "      " << ft.attempts
        << "      " << ft.percent << endl;
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = static_cast<float>(ft.made) / static_cast<float>(ft.attempts);
    else
        ft.percent = 0.0f;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
        
    target.attempts += source.attempts;
    target.made += source.made;
    return target;
}