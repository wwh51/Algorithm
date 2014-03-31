
	void reverse_words(string& s)
	{		
		int iStart = 0;
		while(iStart < s.size() && s[iStart] == ' ') // remove spaces in the front
			++iStart;
		if(iStart == s.size())
		{
			s= "";
			return;
		}

		int iEnd = iStart+1;
		int index = iStart+1;
		int iWordStart = iStart;
		while(iEnd < s.size())
		{
			if(s[iEnd] != ' ')
			{
				if(iWordStart < 0)
					iWordStart = index;
				s[index++] = s[iEnd];
			}
			else
			{
				if(s[iEnd-1] != ' ')
				{
					if(iWordStart >= 0)
					{
						reverse(s.begin() + iWordStart, s.begin() + index); // reverse word
						iWordStart = -1;
					}					
					s[index++] = s[iEnd];
				}	
			}
			iEnd++;
		}

		if(s[index-1] != ' ') // reverse the last word
		{
			iEnd = index;
			reverse(s.begin() + iWordStart, s.begin() + iEnd);
		}
		else
			iEnd = index - 1;		
		
		s = s.substr(iStart, iEnd-iStart);
		reverse(s.begin(), s.end());
	}

	TEST(TEST_UTILS, reverse_words_1)
	{
		string s = "a";
		reverse_words(s);
		EXPECT_EQ(s,"a");
		s = "";
		reverse_words(s);
		EXPECT_EQ(s,"");

		s = "   a";
		reverse_words(s);
		EXPECT_EQ(s,"a");

		s = "   this   is   blue  sky      ";
		reverse_words(s);
		EXPECT_EQ(s,"sky blue is this");

		s = "   this   is   blue  sky";
		reverse_words(s);
		EXPECT_EQ(s,"sky blue is this");

		s = "this   is   blue  sky   ";
		reverse_words(s);
		EXPECT_EQ(s,"sky blue is this");

		s = "this";
		reverse_words(s);
		EXPECT_EQ(s,"this");

		s = "this  ";
		reverse_words(s);
		EXPECT_EQ(s,"this");

		s = "   this  ";
		reverse_words(s);
		EXPECT_EQ(s,"this");
	}
