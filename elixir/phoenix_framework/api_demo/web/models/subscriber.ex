defmodule ApiDemo.Subscriber do
  use Ecto.Model
  alias ApiDemo.Repo
  alias ApiDemo.Subscriber

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

  def list() do
    Repo.all Subscriber
  end

  def get(%{phone_number: phone_number}) do
    Repo.get_by Subscriber, phone_number: phone_number
  end

end
