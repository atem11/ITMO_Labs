#include<bits/stdc++.h>

using namespace std;

const int Inf = 1e9 + 7;

struct Node
{
	Node *l;
	Node *r;
	Node *p;
	int v;
	Node(int v1)
	{
	    p = NULL;
	    l = NULL;
	    r = NULL;
	    v = v1;
	}
	Node(){};
};
Node *root;

void rightRotate(Node *P)
{
	Node *T = P->l;
	Node *B = T->r;
	Node *D = P->p;
	if(D)
	{
		if(D->r == P) D->r = T;
		else D->l = T;
	}
	if(B)
		B->p = P;
	T->p = D;
	T->r = P;
	P->p = T;
	P->l = B;
}

void leftRotate(Node *P)
{
	Node *T = P->r;
	Node *B = T->l;
	Node *D = P->p;
	if(D)
	{
		if(D->r == P) D->r = T;
		else D->l = T;
	}
	if(B)
		B->p = P;
	T->p = D;
	T->l = P;
	P->p = T;
	P->r = B;
}

void Splay(Node *T)
{
	while(true)
	{
		Node *p = T->p;
		if(!p) break;
		Node *pp = p->p;
		if(!pp)
		{
			if(p->l == T)
				rightRotate(p);
			else
				leftRotate(p);
			break;
		}
		if(pp->l == p)
		{
			if(p->l == T)
			{
				rightRotate(pp);
				rightRotate(p);
			}
			else
			{
				leftRotate(p);
				rightRotate(pp);
			}
		}
		else
		{
			if(p->l == T)
			{
				rightRotate(p);
				leftRotate(pp);
			}
			else
			{
				leftRotate(pp);
				leftRotate(p);
			}
		}
	}
	root = T;
}

Node* findv(int v)
{
    if (!root) return NULL;
    Node* T = root;
    while (T != NULL && T->v != v)
    {
        if (T->v > v)
            if (T->l != NULL)
            {
                T = T->l;
            }
            else
            {
                break;
            }
        else
            if (T->r != NULL)
            {
                T = T->r;
            }
            else
            {
                break;
            }
    }
    return T;
}

void ins(int v)
{
	if(!root)
	{
	    root = new Node(v);
		return;
	}
	Node *P = root;
	while(true)
	{
		if(P->v == v) break;
		if(v < (P->v) )
		{
			if(P->l) P = P->l;
			else
			{
				P->l = new Node(v);
				P->l->p = P;
				P = P->l;
				break;
			}
		}
		else
		{
			if(P->r) P = P->r;
			else
			{
				P->r = new Node(v);
				P->r->p = P;
				P = P->r;
				break;
			}
		}
	}
	Splay(P);
}

Node* exists(int v)
{
	if (!root) return NULL;
	Node *P = root;
	while(P)
	{
		if(P->v == v)
			break;
		if(v < (P->v))
		{
			if(P->l)
				P = P->l;
			else
				break;
		}
		else
		{
			if(P->r)
				P = P->r;
			else
				break;
		}
	}
	Splay(P);
	if(P->v == v) return P;
	else return NULL;
}

void del(int v)
{
	Node *N = exists(v);
	if (N != NULL && N->p == NULL && N->r == NULL && N->l == NULL)
    {
        root = NULL;
        free(N);
        return;
    }
	if(!N) return;
	Splay(N);
	Node *P = N->l;
	if(!P)
	{
		root = N->r;
		root->p = NULL;
		free(N);
		return;
	}
	while(P != NULL && P->r) P = P->r;
	if(N->r)
	{
		P->r = N->r;
		N->r->p = P;
	}
	root = N->l;
	root->p = NULL;
	free(N);
	return;
}


int next(int v)
{
    bool f = false;
    int res = Inf;
    Node* T = findv(v);
    if (T == NULL)
    {
        return res;
    }
    if (T->v != v)
    {
        ins(v);
        f = true;
        T = findv(v);
    }
    if (T->r != NULL)
    {
        T = T->r;
        while (T != NULL)
        {
            res = T->v;
            T = T->l;
        }
    }
    else
    {
        if (T->p == NULL)
        {
            if (f) del(v);
            return res;
        }
        while (T->p != NULL && T->p->r == T)
        {
            T = T->p;
        }
        if (T->p == NULL)
        {
            if (f) del(v);
            return res;
        }
        res = T->p->v;
    }
    if (f) del(v);
    return res;
}

int prev(int v)
{
    int res = Inf;
    bool f = false;
    Node* T = findv(v);
    if (T == NULL)
    {
        return res;
    }
    if (T->v != v)
    {
        ins(v);
        f = true;
        T = findv(v);
    }
    if (T->l != NULL)
    {
        T = T->l;
        while (T != NULL)
        {
            res = T->v;
            T = T->r;
        }
    }
    else
    {
        if (T->p == NULL)
        {
            if (f) del(v);
            return res;
        }
        while (T->p != NULL && T->p->l == T)
        {
            T = T->p;
        }
        if (T->p == NULL)
        {
            if (f) del(v);
            return res;
        }
        res = T->p->v;
    }
    if (f) del(v);
    return res;
}

void print(Node* T)
{
    if (T->l != NULL)
        print(T->l);
    cout << T->v << ' ';
    if (T->r != NULL)
        print(T->r);
}

int main()
{
	ios_base::sync_with_stdio(0);
    string s;
    int x;
    while (cin >> s)
    {
        cin >> x;
        if (s == "insert")
        {
            ins(x);
        }
        if (s == "delete")
        {
            del(x);
        }
        if (s == "exists")
        {
            if (exists(x)) cout << "true" << '\n';
            else cout << "false" << '\n';
        }
        if (s == "next")
        {
            int z = next(x);
            if (z == Inf) cout << "none\n";
            else cout << z << '\n';
        }
        if (s == "prev")
        {
            int z = prev(x);
            if (z == Inf) cout << "none\n";
            else cout << z << '\n';
        }
        if (s == "p")
            print(root);
    }
    return 0;
}
