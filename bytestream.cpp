void insert(const uint64& g)
	{
		// avoid loops for performance
		if (guid[0] == 0) { guid[0] = g; return; }
		else if (g <= guid[0]) { if (guid[3]) guid[4] = guid[3]; if (guid[2]) guid[3] = guid[2]; if (guid[1]) guid[2] = guid[1]; guid[1] = guid[0]; guid[0] = g; return; }
		if (guid[1] == 0) { guid[1] = g; return; }
		else if (g <= guid[1]) { if (guid[3]) guid[4] = guid[3]; if (guid[2]) guid[3] = guid[2]; guid[2] = guid[1]; guid[1] = g; return; }
		if (guid[2] == 0) { guid[2] = g; return; }
		else if (g <= guid[2]) { if (guid[3]) guid[4] = guid[3]; guid[3] = guid[2]; guid[2] = g; return; }
		if (guid[3] == 0) { guid[3] = g; return; }
		else if (g <= guid[3]) { guid[4] = guid[3]; guid[3] = g; return; }
		guid[4] = g;
	}
	void force_insert_front(const uint64& g)
	{
		if (guid[3]) guid[4] = guid[3]; if (guid[2]) guid[3] = guid[2]; if (guid[1]) guid[2] = guid[1]; guid[1] = guid[0]; guid[0] = g;
	}
	void remove(const uint64& g)
	{
		// avoid loops for performance
		if (guid[0] == g) { if (guid[1]) guid[0] = guid[1]; else { guid[0] = 0; return; } if (guid[2]) guid[1] = guid[2]; else { guid[1] = 0; return; } if (guid[3]) guid[2] = guid[3]; else { guid[2] = 0; return; } if (guid[4]) guid[3] = guid[4]; else { guid[3] = 0; return; } guid[4] = 0; return; }
		if (guid[1] == g) { if (guid[2]) guid[1] = guid[2]; else { guid[1] = 0; return; } if (guid[3]) guid[2] = guid[3]; else { guid[2] = 0; return; } if (guid[4]) guid[3] = guid[4]; else { guid[3] = 0; return; } guid[4] = 0; return; }
		if (guid[2] == g) { if (guid[3]) guid[2] = guid[3]; else { guid[2] = 0; return; } if (guid[4]) guid[3] = guid[4]; else { guid[3] = 0; return; } guid[4] = 0; return; }
		if (guid[3] == g) { if (guid[4]) guid[3] = guid[4]; else { guid[3] = 0; return; } guid[4] = 0; return; }
		if (guid[4] == g) guid[4] = 0;
	}
	bool hasGuid(const uint64& g) const
	{
		return g && (guid[0] == g || guid[1] == g || guid[2] == g || guid[3] == g || guid[4] == g);
	}
	bool operator<(const Lfg5Guids& x) const
	{
		// not neat, but fast xD
		if (guid[0]<=x.guid[0]) {
			if (guid[0] == x.guid[0]) {
				if (guid[1]<=x.guid[1]) {
					if (guid[1] == x.guid[1]) {
						if (guid[2]<=x.guid[2]) {
							if (guid[2] == x.guid[2]) {
								if (guid[3]<=x.guid[3]) {
									if (guid[3] == x.guid[3]) {
										if (guid[4]<=x.guid[4]) {
											if (guid[4] == x.guid[4]) return false; else return true;
										} else return false;
									} else return true;
								} else return false;
							} else return true;
						} else return false;
					} else return true;
				} else return false;
			} else return true;
		} else return false;
	}
	bool operator==(const Lfg5Guids& x) const
	{
		return guid[0] == x.guid[0] && guid[1] == x.guid[1] && guid[2] == x.guid[2] && guid[3] == x.guid[3] && guid[4] == x.guid[4];
	}
