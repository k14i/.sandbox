defmodule ApiDemo.Subscriber do
  use Ecto.Model
  # import Ecto.Query
  alias ApiDemo.Repo
  alias ApiDemo.Subscriber

  # validate subscriber,
  #   phone_number: present()
  #   sim_id: present()
  #   status: present()

  schema "subscribers" do
    field :phone_number, :string
    # field :sim_id, :string
    # field :status, :string, default: "active"
    # field :contracted_at, :datetime, default: nil
    # field :terminated_at, :datetime, default: nil
    timestamps
  end

  def list do
    Repo.all Subscriber
  end

  def get %{phone_number: phone_number} do
    # query = from s in Subscriber,
    #   where: s.phone_number == ^phone_number,
    #   select: s
    # Repo.all query
    Repo.get_by Subscriber, phone_number: phone_number
  end

end
