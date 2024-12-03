//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
//   #pragma comment(linker, "/STACK:2000000") // use to increase stack size
// using namespace __gnu_pbds; // use to make ordered_set

// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered set

// #include &lt;bits/stdc++.h&gt;

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define yes printf("YES\n")
#define no printf("NO\n")
#define pi 2 * acos(0.0)
#define all(v) v.begin(), v.end()
#define endl '\n'

const int N = 2e5 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
int ip1, ip2, length;
struct rafi
{
    pair<int, int> pref[N];
};

pair<int, int> pw[N], ipw[N];
rafi has[2];
string str, rev;

struct binar
{
    pair<int, int> sum;
};

binar tree[2][4 * N];

int multinverse(long long n, long long k, int mod)
{
    // compute (a^b)%mod
    int ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n += mod;
    while (k)
    {
        if (k & 1)
            ans = (long long)ans * n % mod;
        n = (long long)n * n % mod;
        k >>= 1;
    }
    return ans;
}

void precalc()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ip1 = multinverse(p1, mod1 - 2, mod1);
    ip2 = multinverse(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

void make_hash(string &s, int index)
{ // O(n)
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        has[index].pref[i].first = (s[i] * 1LL * pw[i].first) % mod1;
        // if (i)
        //     has[index].pref[i].first = (has[index].pref[i].first /*+ has[index].pref[i - 1].first*/) % mod1;
        has[index].pref[i].second = (s[i] * 1LL * pw[i].second) % mod2;
        // if (i)
        //     has[index].pref[i].second = (has[index].pref[i].second /*+ has[index].pref[i - 1].second*/) % mod2;
    }
}

pair<int, int> get_hash(int i, int j, int index) // starting and ending index of substring like full string (0,n-1);
{
    pair<int, int> hs({0, 0});
    hs.first = has[index].pref[j].first;
    if (i)
        hs.first = (hs.first - has[index].pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = has[index].pref[j].second;
    if (i)
        hs.second = (hs.second - has[index].pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}

// checking palindrome
bool is_palindromr(int i, int j, int k, int l)
{
    return get_hash(i, j, 0) == get_hash(k, l, 1);
}

// adding two pair
pair<int, int> add(int mode, int left, int right)
{
    return {(tree[mode][left].sum.first * 1LL + tree[mode][right].sum.first) % mod1, (tree[mode][left].sum.second * 1LL + tree[mode][right].sum.second) % mod2};
}

// change char to 'x'
pair<int, int> change_char(int index, int i,char c) //  (mode,index)
{
    has[index].pref[i].first = 1LL * c * pw[i].first % mod1;
    // if (i)
    //     has[index].pref[i].first = (has[index].pref[i].first + has[index].pref[i - 1].first) % mod1;
    has[index].pref[i].second = 1LL * c * pw[i].second % mod2;
    // if (i)
    //     has[index].pref[i].second = (has[index].pref[i].second + has[index].pref[i - 1].second) % mod2;

    return {has[index].pref[i].first, has[index].pref[i].second};
}

// building binary tree
void build(int index, int left, int right, int mode)
{
    if (left == right)
    {
        tree[mode][index].sum = has[mode].pref[left]; // check
        return;
    }
    int mid = (left + right) >> 1;
    build(2 * index, left, mid, mode);
    build(2 * index + 1, mid + 1, right, mode);
    tree[mode][index].sum = add(mode, 2 * index, 2 * index + 1);
}

// updating binary tree
void update(int index, int left, int right, int point, int mode,char c)
{
    if (left > point || right < point)
        return;
    if (left == point && right == point)
    {
        tree[mode][index].sum = change_char(mode, point,c);
        return;
    }
    int mid = (left + right) >> 1;
    update(2 * index, left, mid, point, mode,c);
    update(2 * index + 1, mid + 1, right, point, mode,c);
    tree[mode][index].sum = add(mode, 2 * index, 2 * index + 1);
}

// searching in binary tree
pair<int, int> query(int index, int left, int right, int mode, int l, int r)
{
    if (left > r || right < l)
        return {0, 0};
    else if (left >= l && right <= r)
        return tree[mode][index].sum;

    pair<int, int> value{0, 0};
    int mid = (left + right) >> 1;

    auto a = query(2 * index, left, mid, mode, l, r);
    value.first = (value.first + a.first) % mod1;
    value.second = (value.second + a.second) % mod2;

    a = query(2 * index + 1, mid + 1, right, mode, l, r);
    value.first = (value.first * 1LL + a.first) % mod1;
    value.second = (value.second * 1LL + a.second) % mod2;

    return value;
}

// solving ans
template <typename T>
void solve(T case_number)
{
    int sz, q;
    cin >> sz >> q;

    cin >> str;
    rev = str;
    reverse(rev.begin(), rev.end());

    precalc();
    make_hash(str, 0);
    make_hash(rev, 1);

    build(1, 0, str.size() - 1, 0); // normal string
    build(1, 0, str.size() - 1, 1); // reverse string

    while (q--)
    {
        int i;
        cin >> i;
        if (i == 1)
        {
            int point;
            char c;
            cin >> point >> c;
            // update
            update(1, 0, sz - 1, point - 1, 0, c);            // for normal string
            update(1, 0, sz - 1, sz - (point - 1) - 1, 1, c); // for reverse string
        }
        else
        {
            int left, right;
            cin >> left >> right;
            // query
            auto a = query(1, 0, sz - 1, 0, left - 1, right - 1);

            a.first = (a.first * 1LL * ipw[left - 1].first) % mod1;
            a.second = (a.second * 1LL * ipw[left - 1].second) % mod2;

            // cout << a.first << " " << a.second << endl;
            auto b = query(1, 0, sz - 1, 1, sz - (right - 1) - 1, sz - (left - 1) - 1);

            b.first = (b.first * 1LL * ipw[sz - (right - 1) - 1].first) % mod1;
            b.second = (b.second * 1LL * ipw[sz - (right - 1) - 1].second) % mod2;

            //  cout << b.first << " " << b.second << endl;
            if (a == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
int main()
{
    Taratari;
    int Testcase = 1, index = 1;
    // cin >> Testcase;

    while (Testcase--)
    {
        // cout << "Case " << index << ": ";
        solve(index);
        index++;
    }

    return 0;
}

/*
data:
1)equal_range(.begin(),.end(),value);
     :: return iterator of lower_bound(value) & upper_bound(value);{pair maybe}
2)binary_search()
     :: return true or false
3)next_permutation()
     :: return next permutation of a string
4)unique()
     ::return iterator where single unique value are placed
     1 2 2 2 3 3 2 1 1 4 => 1 2 3 2 1 4 2 1 1 4

     ::we can use resize to get only unique value in vector
     => variable_name.resize(unique(v.begin(),v.end())-v.begin());
5)making structure:
     ::struct info
       {
        ll maximum;
        ll minimum;
       } tree[400009];

     ::accessing by tree[index].maximum,tree[index].minimum
6)priority queue:
     ::typedef data_type(pair<ll, pair<ll, ll>>) pi;
     ::priority_queue<pi, vector<pi>> p;                  -> "increasing order"
     ::priority_queue<pi, vector<pi>, greater<pi>> p;     -> "decreasing order"
7)__builtin_popcountll(number)
     ::count number of 1 in a number

8)o_set<data_type> variable;           -> kind of a set but can find the value in index
     ::variable.find_by_order(index)   -> find the value in index return iterator
     ::variable.order_of_key(value)    -> find number of value less then value

*/

// First greedy
// Use sorting
// Use dp [dynamic programming]
// Use recursive
// Use dfs
// Use math
// Use bit masking
// Make equation sorter[a.u - b.u < a.v - b.vqe]

/*
                                                                                                                             .
                                                                                                      `;|$&@&$%%%|||%%$&@&%' .
    '$$%|!!!;;;!!!||%$@@&%;'                                                                  .:%&&%!:::::::::::::::::::::|!..
   .||:::::::::::::::::::::::;|$@$!`                                                     `|&$!::::::::::::::::::::::::::::!|'.
   ;%:::::::::::::::::::::::::::::::;|&&!`                                          `|&$!:::::::::::::::::::::::::::::::::!%:.
  `||:::::::::::::::::::::::::::::::::::::!$&|'                                 '%&|::::::::::::::::::::::::::::::::::::::;%;.
  :%;:::::::::::::::::::::::::::::::::::::::::!$@&;.                        '%@%;::::::::::::::::::::::::::::::::::::::::::%!`
  !%:::::::::::::::::::::::::::::::::::::::::::::!%&@&!.                .!&@$|:::::::::::::::::::::::::::::::::::::::::::::%!`
 .||:::::::::::::::::::::::::::::::::::::::::::::::;|$$&@&;.'%@@@@$!``%@&$%!:::::::::::::::::::::::::::::::::::::::::::::::|!'
 `|!:::::::::::::::::::::::::::::::::::::::::::::::;!|%$$&@$;:::::;|&@&$%!:::::::::::::::::::::::::::::::::::::::::::::::::||'
 :|;::::::::::::::::::::::::::::::::::::::::::;%&@@@@$%|!!;:::::;!|%&@##@&$$%!:::::::::::::::::::::::::::::::::::::::::::::||:
 :%;:::::::::::::::::::::::::::::::::::!%&@$|;'````.```..```...```..``..```:|&@@|;:::::::::::::::::::::::::::::::::::::::::||:
 :%;::::::::::::::::::::::::::::::!$&|:`.`..................................`````;$&|;:::::::::::::::::::::::::::::::::::::||'
 :%;::::::::::::::::::::::::::|&$:`.........``.................................`.````;$$!::::::::::::::::::::::::::::::::::||'
 '|!::::::::::::::::::::::;%$!`.`````.................................................``:%$!:::::::::::::::::::::::::::::::%!`
 `||:::::::::::::::::::;|$!`..```.......................................................```;$%;::::::::::::::::::::::::::::%!`
  !|:::::::::::::::::!$%'`.............................................................``..``'%&|;::::::::::::::::::::::::;%;.
  ;%;::::::::::::::!$!```..............................................................`...````'%@$|;:::::::::::::::::::::!%:.
  '|!::::::::::::!$!`.`....................................................................``````'%&$$|:::::::::::::::::::||`.
  .!|::::::::::;%!   ..........................................................................````;&&$$%;::::::::::::::::%! .
   :%;::::::::%%`          ...````````.........`.............................................```.``.'%&$%$%!:::::::::::::;%; .
   .!|::::::!%;     .               .....```..```````````.``........................................``!&$$%%%!:::::::::::!|' .
    :|;::::|%'    ..                                   ....``..........................................:$&$$$$%;:::::::::%!  .
     !%::;%|'``.....                      .....```..................................................````:$&$$%$$|;::::::!%'  .
     '|!;%|`.......`.`.........````````..`.......```...........`````.................................````:%&$$$$$%!:::::%!   .
      ;$$|`...`':'..`.`````....`````|!`````...................```.````.................`....````..........:$&$%%%%$|:::!|'   .
      .||``.``'|!```...........``.`:|;````;!'.``..............```.::```...................`'!:.`.......`..`;$&%%%$$$|;;%;    .
      ;|'...``!|'``.`````..........;|:``.:$|`...................``;|:......................'|!```.......``.`!&$%%$%$$%$!     .
     :|:.``..'|!.``..``````......``!%:.`:%&|```...............```'!%|:````.`....```.......`'|!..............'%&$%$$$$@|.     .
    `|;..````:|:..``;|'.```.......`;%;`:%&#!```..................:|$%:``'|!``````.......```'|!``..........```;$&$%$$@|.      .
    !|``...``;|:`..'%%'..```..```:%&&!'!&&$!`.```.``..........```;%&%```|&;``:%!```....```.'|;.``...`.``..`.``|&$$$@|        .
   :|:.``````;|:``;$@%:````````'|$;:%%;%&!||`....`''........``..:|$&!``!&&&;``|#$'``....``.:|;`````..`!|'``..`:$&&&;         .
   !!````||``:|;`!$@#$:`....``:%|:::;$$$%`;|'....`:'...........`;%&%:`!$;:!&%'!$$&!`...```.;|'`..```..;$;....``|#&$;         .
  :|:..`:%;```||;%&@@&;``````;$!:'` .;&@; `|;````.::`........``:|%&!`|$;:` `|$$|;%@@|'....`||`````..``;$|'..```;%!||.        .
  |!.```!|'```;$%$&$&&|'`'|$$&|:'.    `'.  !|`..`.';'.........'!%&%;|%:'.  '%@#&: `|&%:```:|;`````````;$%:```..'||!%:        .
 '|:```'%!`..``!&&&%$&%:`.`:%%|$@&!`       `|!```.'!;`....``.`;|$&%%%:;|&$:.        :&@%;`!|`.`````..`;$$;::`.``!%;%!        .
 !|`..`!$;..`..:&@$|%&&!'`'%%:`    .;$@$:.  :|:...`;|;`.`.`..:|%&@&&%:.             .|&$&@$;.....`````;$$!!!'..`;%;!|`       .
.|!`..:$%'```.`;||||%&@$;`!%;`            '!!|%:.``;|!'```..'!%&#&;'.                !&;````.......```;$$||!'..`:%!;%;       .
`|;..`!&|````.:!||||%&&&%|%!'.                :%;``;||;````'!|$@%:`   `:|$@#####%`   :$!``..``........;$%|||:`.`'||:%!       .
'|:..:|&|`''``:|||||%&%'%@!.;@@@#####@&$|!'.   `|!';|%!'```;%$&||&&@@@@@&&&&&@#|     :$|'``.......``.`!$%|||;```'||:||`      .
:|'.`;%&!.:;``;|||||%&%`   `|@&&&&&&&&&&@&'      ;&$%|!'.`;|$&;.!@&&&&&&&&&&&@#|.    '%|'``.......````!&%||%!`.`'||:;%:      .
:|'.`;%$!`;!'`;|||||%&|.   '%|;%&&&&&&&&@$`        !&$|:`;%&%`  !%`.!&&&&&$$$$@%`    '%|'``.```...````|&%|||!'.`'||:;%;      .
:|'.'!%$!`;|:`;|||||%&|.   :;  `|%|%%|||$|.          ;$|;$&;    ::  `!%%|%||||&%`    '%%'``.```.''```'%$%|||!'.`'||::%!      .
'|:`:|%$!`;|;`;|||||%&!    ;$||||%|%%|||&;             .'`      '%|||||%%%||||&%.    '%|'``...`.':`.`:%$|||||:..:|!::||.     .
`!;.:|%&!`;||:;||||%$&;    ;$||||||||||$%'                      .|$|||%%%%|||%@|     '$|'.`..`.`:!:``!$%|||||:``;$!::!|`     .
.||`:|%&|`;||;;||||%&%`    '%%||%%%||%%&!                        :%|||%|||%||$$'     :$!`..`````;|:``|&||||||:.`|&!::!|'     .
`$%''!|&%';||||||||%&!      !$|'.```:|&%.                         ;$%'     :$&:      ;$!`......:||:`:%$||||||:.:$$;::!%:     .
'$&;'!|$$::|||||||%&%`      .|&:   .!@|.                           .|&|`.`;&$'       !&;`....``;||;`!$%||||||:`!&%;::!%:     .
:%$|';|%&!'!||||||%&%'  ......`!@##@!.                                '|&&|'.`....  .|$:...```:|||;'%$|||||%$;:$&|;::!%:     .
;%;%|;||&$::||||||%$$:..``````````.      ;;                            ...````````..`|%'....`'!|||:;$%||||%$$!|&$|;::!%:     .
;%;|$|!|%&|`;%|||||%&!..`````````...     .|#################@@$;.      ..``````````.:$|'```.`;||||;%$||%%%%&$%&$%|:::!|'     .
:|;;%&$||%$;:$$||||%&%'..````````..       '$##&;``````````````:$&'      ..```````.. ;$!`````:||||!%$%|$&$|$#@&$%%!:::||`     .
'|!:|$@&%%$$;;&$||||%&|. ........         :@$:`````````````````|$:         ......   !$:.```'!%%||%$%|%&@$$##@$%$%;:::|!.     .
 !%:!%$@&%%@@!%@%||||%&%`                 '$!``````````````````|%`                 `%%'``.'!%&&%$@$%%&#&@##@$%%$|;:::%!      .
 `%&&@$|!$&&$$#&&$%|||%&#%`               .|$:````````````````:%:                  :$!````;|$&%%@&%$&%&@; `|@@&%;:::;|:      .
          '&&';!:%&%|||$&$$@$:             .|&;``````````````;%:               .;&@@$:`.`;|$@$$@&$&|'%%.       .:|$&@|.      .
            `'    ;&$||%&&%||%&@|`           `%&!``````````:%!.            `!&@$%%%&|`.`:|$@&&#@&$:                          .
                    !&$%%&#@%|||%$&@%'          .';;'`...''.          `!&#&%|||||%$$;`.:%&#@@#@@!.                           .
         .;%&&$$&!    :&&$&%|@$%%&@$%%$@#@|:.                 .`;%&@&@$:``:%&$%%%&@%``:%@#@||#|!$!'';|$@!                    .
          ;&%:```'|$:    :$#%.`|@@@%!&#&;```':;|&#@@@@@@@&$%|!;:::|&!.       '$%``|;`;&|. .;!|$;``'!%&@;                     .
           .%&$$$%|;;$%`       `%$!':%%`         `|&|::::::::::;$%`          ;&$!|%|&|.   `%@$$&&&&@#%`                      .
             `;;;;;;;;;;`     ||      '$;           :$|:::::'!&!           `%|.  !|` !|.           .::.                      .

*/