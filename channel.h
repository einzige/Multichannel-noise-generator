#ifndef CHANNEL_H
#define CHANNEL_H

#include "ifilter.h"
#include <QString>

class Channel
{
public:
    enum Identifier { R=0, G, B,
                      H,   S, L,
                      UNDEFINED };

    Channel();
    Channel(Channel::Identifier, IFilter*);
    Channel(Channel::Identifier, IFilter*, const QImage&);

    IFilter*   getFilter();
    Identifier getID() const;
    void       fetchFrom(const QImage&);
    QImage     getImage();
    void       applyFilter(IFilter*);

    static Channel::Identifier getChannelByName(const QString& name);

private:
    IFilter*   filter;
    Identifier identifier;
    QImage     image;
};

#endif // CHANNEL_H
