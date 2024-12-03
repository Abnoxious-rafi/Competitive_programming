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

const int N = 2e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
int ip1, ip2;
pair<int, int> pw[N], ipw[N], pref[N];
string str;

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

void make_hash(string &s)
{ // O(n)
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
    if (i)
      pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
    if (i)
      pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
  }
}

pair<int, int> get_hash(int i, int j) // starting and ending index of substring like full string (0,n-1);
{
  pair<int, int> hs({0, 0});
  hs.first = pref[j].first;
  if (i)
    hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * ipw[i].first % mod1;
  hs.second = pref[j].second;
  if (i)
    hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * ipw[i].second % mod2;
  return hs;
}

int get_lcsubstr(int i, int j, int x, int y)
{
  int left = 1, right = min(j - i + 1, y - x + 1), mid, ans = 0;
  while (left <= right)
  {
    mid = (left + right) >> 1;
    if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1))
    {
      ans = mid;
      left = mid + 1;
    }
    else
      right = mid - 1;
  }
  return ans;
}

template <typename T>
void solve(T case_number)
{
  cin >> str;

  precalc();
  make_hash(str);
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