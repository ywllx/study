class Screen {
public:
    typedef std::string::size_type index;
    Screen::Screen(const std::string &con, index h, index w):
        contens(con), height(h), width(w)
    {
    }

private:
    std::string contents;
    index cursor;
    index height, width;
};
