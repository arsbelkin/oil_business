struct Pipe{
    // труба
    std::string name;
    int length;
    int diameter;
    bool is_working;
};

bool is_created(const Pipe &pipe);

std::string work_to_string(const Pipe &pipe);

void edit_work_status(Pipe &pipe);

std::ostream& operator << (std::ostream &os, const Pipe &pipe);

void add_pipe(Pipe &pipe);

void save(const Pipe &pipe);
