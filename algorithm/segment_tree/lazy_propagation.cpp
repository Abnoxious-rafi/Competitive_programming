#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
#define ll long long

ll tree[4 * N];
ll lazy[4 * N];
ll arr[N];
void updateRangeUtil(ll si, ll ss, ll se, ll us, ll ue, ll diff)
{
	if (lazy[si] != 0)
	{
		tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}

		lazy[si] = 0;
	}

	if (ss > se || ss > ue || se < us)
		return;

	if (ss >= us && se <= ue)
	{
		tree[si] += (se - ss + 1) * diff;

		if (ss != se)
		{
			lazy[si * 2 + 1] += diff;
			lazy[si * 2 + 2] += diff;
		}
		return;
	}

	ll mid = (ss + se) / 2;
	updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
	updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

	tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}
void updateRange(ll n, ll us, ll ue, ll diff)
{
	updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
	if (lazy[si] != 0)
	{
		tree[si] += (se - ss + 1) * lazy[si];

		if (ss != se)
		{
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}

		lazy[si] = 0;
	}

	if (ss > se || ss > qe || se < qs)
		return 0;

	if (ss >= qs && se <= qe)
		return tree[si];

	ll mid = (ss + se) / 2;
	return getSumUtil(ss, mid, qs, qe, 2 * si + 1) + getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

ll getSum(ll n, ll qs, ll qe)
{
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		cout << "Invalid Input";
		return -1;
	}

	return getSumUtil(0, n - 1, qs, qe, 0);
}

void Build(ll ss, ll se, ll si)
{
	if (ss > se)
		return;

	if (ss == se)
	{
		tree[si] = arr[ss];
		return;
	}

	ll mid = (ss + se) / 2;
	Build(ss, mid, si * 2 + 1);
	Build(mid + 1, se, si * 2 + 2);

	tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void constructST(ll n)
{
	Build(0, n - 1, 0);
}

int main()
{
	ll n, m;
	cin >> n >> m;

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	constructST(n);

	while (m--)
	{
		ll x;
		cin >> x;
		if (x == 1)
		{
			ll y, z;
			ll value;
			cin >> y >> z >> value;
			updateRange(n, y - 1, z - 1, value);
		}
		else
		{
			ll k;
			cin >> k;
			cout << getSum(n, k - 1, k - 1) << endl;
		}
	}

	return 0;
}
