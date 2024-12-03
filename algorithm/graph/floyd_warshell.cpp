//               |******In the name of ALLAH,the Beneficent,the Merciful******|
// coded by Rafi

#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
//   #pragma comment(linxer, "/STACx:2000000") // use to increase stacx size
// using namespace __gnu_pbds; // use to maxe ordered_set

// #include &lt;bits/stdc++.h&gt;

using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;

#define Taratari ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define yes printf("YES\n")
#define no printf("NO\n")
#define pi 2 * acos(0.0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl "\n"
#define cou cout << fixed << setprecision(0)
#define pr pair<int, int>
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

std::ostream &
operator<<(std::ostream &dest, __int128_t value);

const ll N = 500 + 9, inf = 1e15;
int vertex, edge, queries;
ll weight;
ll dist[N][N];

template <typename T>
void solve(T case_number)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;

    cin >> vertex >> edge >> queries;
    int u, v;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v >> weight;
        dist[u][v] = min(dist[u][v], weight);
        dist[v][u] = min(dist[v][u], weight);
    }
    for (int k = 1; k <= vertex; k++)
        for (int i = 1; i <= vertex; i++)
            for (int j = 1; j <= vertex; j++)

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while (queries--)
    {
        cin >> u >> v;
        cout << ((dist[v][u] == 1e15) ? -1 : dist[u][v]) << endl;
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

std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
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
5)maxing structure:
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

8)o_set<data_type> variable;           -> xind of a set but can find the value in index
      ::variable.find_by_order(index)   -> find the value in index return iterator
      ::variable.order_of_xey(value)    -> find number of value less then value

*/

// First greedy
// Use sorting
// Use dp [dynamic programming]
// Use recursive
// Use dfs
// Use math
// Use bit masxing
// Maxe equation sorter[a.u - b.u < a.v - b.vqe]

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