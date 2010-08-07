//any numerical value to string
template <class T>
std::string int2str(T x) {
    std::stringstream buffer;
    std::string s;
    buffer << x;
    s = buffer.str();
    return s;
}
