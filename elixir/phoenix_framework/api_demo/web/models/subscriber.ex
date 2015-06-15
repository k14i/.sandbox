defmodule ApiDemo.Subscriber do
  use Ecto.Model

  # validate subscriber,
  #   phone_number: present()
  #   sim_id: present()
  #   status: present()

  schema "subscribers" do
    field :phone_number #, :string
    #  field :sim_id, :string
    #  field :status, :string
    timestamps
  end

end
