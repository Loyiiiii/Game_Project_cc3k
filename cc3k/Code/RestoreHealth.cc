export module restore_health;

export class RestoreHealth : public Potion {
public:
    RestoreHealth(): Potion{Potion_Type::HEALTH_RESTORE, false, 10, 'P'}
}
