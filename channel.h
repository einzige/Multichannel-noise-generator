#ifndef CHANNEL_H
#define CHANNEL_H

#include "ifilter.h"

class Channel
{
public:
    enum Identifier { R=0, G, B,
                      H,   S, L,
                      UNDEFINED };

    Channel();
    Channel(Channel::Identifier, IFilter*);
    Channel(Channel::Identifier, IFilter*, const QImage&);

    IFilter*   GetFilter();
    Identifier GetID() const;
    void       FetchFrom(const QImage&);
    QImage     GetImage();
    void       ApplyFilter(IFilter*);

private:
    IFilter*   mFilter;
    Identifier mIdentifier;
    QImage     mImage;
};

#endif // CHANNEL_H
