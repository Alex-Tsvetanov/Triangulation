	vector < set < int > > all2;
	set < int > curr2;
	vector < int > curr22;

	void gen2 (int i = 0, int last = -1)
	{
		if (i == (int)polygon.size ())
		{
			if (!Intersect (curr22))
				all2.push_back (curr2);
			return;
		}
		if (last == -1)
			for (int start = 0 ; start < (int)polygon.size () ; start ++)
			{
				curr22.push_back (start);
				curr2.insert (start);
				gen2 (i + 1, start);
				curr2.erase  (start);
				curr22.pop_back ();
			}
		else
			for (auto& x : ln [last])
			{
				curr22.push_back (x);
				curr2.insert (x);
				gen2 (i + 1, x);
				curr2.erase  (x);
				curr22.pop_back ();
			}
	}

	make_func_print_triangulation(gen2_printer, all2, all2Counter)
