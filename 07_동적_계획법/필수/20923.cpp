#include <iostream>
#include <deque>

using namespace std;

deque<int> do_deck, su_deck;
deque<int> do_ground, su_ground;

// 종을 치는 조건 확인
void check_bell() {
    bool do_bell = false;
    bool su_bell = false;

    if (!do_ground.empty() && !su_ground.empty()) {
        if (do_ground.front() + su_ground.front() == 5)
            su_bell = true;
        if (do_ground.front() == 5 || su_ground.front() == 5)
            do_bell = true;
    }
    else if (!do_ground.empty() && su_ground.empty()) {
        if (do_ground.front() == 5)
            do_bell = true;
    }
    else if (do_ground.empty() && !su_ground.empty()) {
        if (su_ground.front() == 5)
            do_bell = true;
    }

    if (do_bell) {
        while (!su_ground.empty()) {
            do_deck.push_back(su_ground.back());
            su_ground.pop_back();
        }
        while (!do_ground.empty()) {
            do_deck.push_back(do_ground.back());
            do_ground.pop_back();
        }
    }
    else if (su_bell) {
        while (!do_ground.empty()) {
            su_deck.push_back(do_ground.back());
            do_ground.pop_back();
        }
        while (!su_ground.empty()) {
            su_deck.push_back(su_ground.back());
            su_ground.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int d, s;
        cin >> d >> s;
        do_deck.push_front(d);
        su_deck.push_front(s);
    }

    bool do_turn = true;

    for (int i = 0; i < m; ++i) {
        if (do_turn) {
            if (!do_deck.empty()) {
                do_ground.push_front(do_deck.front());
                do_deck.pop_front();
            }
        }
        else {
            if (!su_deck.empty()) {
                su_ground.push_front(su_deck.front());
                su_deck.pop_front();
            }
        }

        // 카드 없어지면 즉시 종료
        if (do_deck.empty()) {
            cout << "su\n";
            return 0;
        }
        if (su_deck.empty()) {
            cout << "do\n";
            return 0;
        }

        check_bell();

        do_turn = !do_turn; // 턴 전환
    }

    if (do_deck.size() > su_deck.size()) cout << "do\n";
    else if (do_deck.size() < su_deck.size()) cout << "su\n";
    else cout << "dosu\n";

    return 0;
}
