defmodule ApiDemo.Repo.Migrations.AddFieldsToSubscribers do
  use Ecto.Migration

  def change do
    alter table(:subscribers) do
      add :sim_id, :string
      add :status, :string
    end
  end
end
