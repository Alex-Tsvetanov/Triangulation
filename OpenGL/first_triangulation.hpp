	vector < set < int > > all1;
	
	void gen1 ()
	{
		if (polygon.size () <= 3) return;

		if (polygon.size () == 4) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				all1.push_back ({a});

		if (polygon.size () == 5) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					if (not Intersect ({a, b}))
						all1.push_back ({a, b});

		if (polygon.size () == 6) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					for (auto& c : ln [b]) 
						if (not Intersect ({a, b, c}))
							all1.push_back ({a, b, c});

		if (polygon.size () == 7) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					for (auto& c : ln [b])
						for (auto& d : ln [c])
							if (not Intersect ({a, b, c, d}))
								all1.push_back ({a, b, c, d});

		if (polygon.size () == 8) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					for (auto& c : ln [b])
						for (auto& d : ln [c])
							for (auto& e : ln [d])
								if (not Intersect ({a, b, c, d, e}))
									all1.push_back ({a, b, c, d, e});
	}

	make_func_print_triangulation(gen1_printer, all1, all1Counter)
