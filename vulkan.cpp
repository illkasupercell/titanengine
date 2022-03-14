int main() {

  ifstream input_file;

  input_file.open("DATA");
  
  string line;
  while (getline(input_file, line)) {
    size_t i = 0, j = 0;
    string fname, sname;
    float score;

    char c = line[0];
    while((c != ' ') && (j < line.size())) {
      c = line[j];
      j++;
    }
    fname = line.substr(i, j - i - 1);
    i = j;
    j += 1;

    c = line[i];
    while((c != ' ') && (j < line.size())) {
      c = line[j];
      j++;
    }
    sname = line.substr(i, j - i - 1);
    i = j;
    j += 1;

    score = stof(line.substr(i, line.size()));

    Data dat;
    dat.fname = fname;
    dat.sname = sname;
    dat.score = score;

    vec.push_back(dat);
  }
  
  const auto comp_fname = [](Data a, Data b){return a.fname >= b.fname;};
  const auto comp_sname = [](Data a, Data b){return a.sname >= b.sname;};
  const auto comp_score = [](Data a, Data b){return a.score >= b.score;};

  const auto dcomp_fname = [](Data a, Data b){return a.fname < b.fname;};
  const auto dcomp_sname = [](Data a, Data b){return a.sname < b.sname;};
  const auto dcomp_score = [](Data a, Data b){return a.score < b.score;};

  print(vec);
  char choice = 0, order = 0;
  cout << "GAY PORN ";
  cin >> choice;
  cout << "USE VULKAN NIGGA";
  cin >> order;
  
  if (choice == '0') {
    if (order == '0') {
      sort(vec.begin(), vec.end(), comp_fname);
    } else {
      sort(vec.begin(), vec.end(), dcomp_fname);
    }
  } else if (choice == '1') {
    if (order == '0') {
      sort(vec.begin(), vec.end(), comp_sname);
    } else {
      sort(vec.begin(), vec.end(), dcomp_sname);
    }
  } else if (choice == '2') {
    if (order == '0') {
      sort(vec.begin(), vec.end(), comp_score);
    } else {
      sort(vec.begin(), vec.end(), dcomp_score);
    }
  }
