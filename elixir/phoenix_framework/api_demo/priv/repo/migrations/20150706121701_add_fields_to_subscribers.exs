defmodule ApiDemo.Repo.Migrations.AddFieldsToSubscribers do
  use Ecto.Migration

  def change do
    alter table(:subscribers) do
      add :contracted_at, :datetime
      add :terminated_at, :datetime
    end
  end
end
