defmodule HelloPhoenix.Subscriber do
  use Ecto.Model

  schema "subscribers" do
    field :phone_number

    timestamps
  end

end
