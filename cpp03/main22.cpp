#include <iostream>

class Youtube_Channels
{
    private :
        std::string _name;
        int _subscribers;
        int _videos;
    public :
        Youtube_Channels();
        ~Youtube_Channels();
        Youtube_Channels(const Youtube_Channels& copy);
        Youtube_Channels& operator=(const Youtube_Channels& copy);
        //getters
        std::string get_name() const;
        int get_subscribers() const;
        int get_videos() const;
        //setters
        void set_name(std::string name);
        void set_subscribers(int subscribers);
        void set_videos(int videos);
};

Youtube_Channels::Youtube_Channels()
{
}

Youtube_Channels::~Youtube_Channels()
{
}

Youtube_Channels::Youtube_Channels(const Youtube_Channels& copy)
{
    *this = copy;
}

Youtube_Channels& Youtube_Channels::operator=(const Youtube_Channels& copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_subscribers = copy._subscribers;
        this->_videos = copy._videos;
    }
    return (*this);
}

//getters
std::string Youtube_Channels::get_name() const
{
    return (this->_name);
}

void Youtube_Channels::set_name(std::string name)
{
    this->_name = name;
} 

class hamid_channel : Youtube_Channels
{
    private:
    std::string ll;
    public:
    hamid_channel();
    ~hamid_channel();
    hamid_channel(const hamid_channel& copy);
    hamid_channel& operator=(const hamid_channel& copy);
       

};
int main()
{
    Youtube_Channels channel1;  
}