for (auto i : result)
    {
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;

        cout << u << " " << v << " " << w << endl;
    }