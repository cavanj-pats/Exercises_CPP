bool isleapyear(int inyear){
	if (inyear % 4 == 0) {
		if (inyear % 100 == 0) {
			if (inyear % 400 == 0)
				return true;
			else
				return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}


