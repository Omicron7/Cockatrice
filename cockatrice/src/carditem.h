#ifndef CARDITEM_H
#define CARDITEM_H

#include "abstractcarditem.h"

class CardDatabase;
class CardDragItem;
class CardZone;
class ServerInfo_Card;
class Player;
class QAction;
class QColor;

const int MAX_COUNTERS_ON_CARD = 999;

class CardItem : public AbstractCardItem {
	Q_OBJECT
private:
	CardZone *zone;
	int id;
	bool revealedCard;
	bool attacking;
	bool facedown;
	QMap<int, int> counters;
	QString annotation;
	QString pt;
	bool destroyOnZoneChange;
	bool doesntUntap;
	QPoint gridPoint;
	CardDragItem *dragItem;
	CardItem *attachedTo;
	QList<CardItem *> attachedCards;
	
	QMenu *cardMenu, *ptMenu, *moveMenu;

	void prepareDelete();
public slots:
	void deleteLater();
public:
	enum { Type = typeCard };
	int type() const { return Type; }
	CardItem(Player *_owner, const QString &_name = QString(), int _cardid = -1, bool revealedCard = false, QGraphicsItem *parent = 0);
	~CardItem();
	void retranslateUi();
	CardZone *getZone() const { return zone; }
	void setZone(CardZone *_zone);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPoint getGridPoint() const { return gridPoint; }
	void setGridPoint(const QPoint &_gridPoint) { gridPoint = _gridPoint; }
	QPoint getGridPos() const { return gridPoint; }
	Player *getOwner() const { return owner; }
	void setOwner(Player *_owner) { owner = _owner; }
	int getId() const { return id; }
	void setId(int _id) { id = _id; }
	bool getRevealedCard() const { return revealedCard; }
	bool getAttacking() const { return attacking; }
	void setAttacking(bool _attacking);
	bool getFaceDown() const { return facedown; }
	void setFaceDown(bool _facedown);
	const QMap<int, int> &getCounters() const { return counters; }
	void setCounter(int _id, int _value);
	QString getAnnotation() const { return annotation; }
	void setAnnotation(const QString &_annotation);
	bool getDoesntUntap() const { return doesntUntap; }
	void setDoesntUntap(bool _doesntUntap);
	QString getPT() const { return pt; }
	void setPT(const QString &_pt);
	bool getDestroyOnZoneChange() const { return destroyOnZoneChange; }
	void setDestroyOnZoneChange(bool _destroy) { destroyOnZoneChange = _destroy; }
	CardItem *getAttachedTo() const { return attachedTo; }
	void setAttachedTo(CardItem *_attachedTo);
	void addAttachedCard(CardItem *card) { attachedCards.append(card); }
	void removeAttachedCard(CardItem *card) { attachedCards.removeAt(attachedCards.indexOf(card)); }
	const QList<CardItem *> &getAttachedCards() const { return attachedCards; }
	void resetState();
	void processCardInfo(const ServerInfo_Card &info);

	bool animationEvent();
	CardDragItem *createDragItem(int _id, const QPointF &_pos, const QPointF &_scenePos, bool faceDown);
	void deleteDragItem();
	void drawArrow(const QColor &arrowColor);
	void playCard(bool faceDown);
protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif
