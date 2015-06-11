defmodule ApiDemo.Repo.Migrations.CreateSubscribers do
  use Ecto.Migration

  def change do
    create table(:subscribers) do
      add :phone_number

      timestamps
    end
  end
end
