#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
    public:
        virtual ActionResult use(Entity& other);
        virtual ActionResult open();
};

#endif // ENTITY_H_
