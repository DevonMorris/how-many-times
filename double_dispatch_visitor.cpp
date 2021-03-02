// Note: let this serve as an important lesson to me for thinking
// inheritance was magical and filled with sunshine. Dispatching is algorithmic
// and most definitely can't just make up information that isn't there.
#include <iostream>
#include <string>

// forward declartion necessary
class Packet;

class IVisitor {
    public:
        virtual void visit(Packet* p);
};

class Packet {
    public:
        virtual void accept(IVisitor* v);
};

void IVisitor::visit(Packet* p) {p->accept(this);};
void Packet::accept(IVisitor* v) {v->visit(this);};

// Forward declaration necessary
class YoVisitor;
class HeyVisitor;

class APacket : public Packet {
    public:
        void accept(IVisitor* v) override {v->visit(this);};
};

class BPacket : public Packet {
    public:
        void accept(IVisitor* v) override {v->visit(this);};
};

class YoVisitor : public IVisitor{
    public:
        void visit(Packet* p) override {p->accept(this);};
        void visit(APacket* p) {std::cout << "Yo A" << std::endl;};
        void visit(BPacket* p) {std::cout << "Yo B" << std::endl;};
};

class HeyVisitor : public IVisitor{
    public:
        void visit(Packet* p) override {p->accept(this);};
        void visit(APacket* p) {std::cout << "Hey A" << std::endl;};
        void visit(BPacket* p) {std::cout << "Hey B" << std::endl;};
};

int main()
{
    YoVisitor yo;
    HeyVisitor hey;
    APacket a;
    BPacket b;

    IVisitor* v = &yo;
    Packet* p = &a;

    v->visit(p);
}
